"""
I was fascinated by the internet lectures and how data can manage to find the shortest path. Therefore, I wrote
a program that simulates just that. This program takes in a graph, and compute the shortest path from the location of
the user. After that, the user can freely add and remove edges from the graph to simulate powerline breakdowns and etc.
Then, the user can retrieve the time that it will take to send messages from some interval of nodes. This kind of
simulates sending a message to a group chat where everyone will receive the message. Since I just assumed that there is
only one thread, the times add up. Some people that the user is sending message to might also change their device, which
makes their device receive messages for some time faster or slower. Just to clarify on how the path are being input
"1 2 4" means person 1 and person 2 are connected with a path that takes 4 time unit.
The sample interactions below is what the code is meant to do:

how many total people on the internet are there? 4
how many path ways there are on the internet? 5
which person is the user? 1
please enter three numbers to indicate the two points the path is connecting as well as the length of the path
1 2 4
2 3 3
1 3 8
3 4 9
1 4 8
how many operation will be provided 7
add for add edge
shut down for removing edge
send to indicate send to everyone along l to r
updated to indicate that people from l to r have updated their program and it takes w seconds less to receive something
what operation: send to
2 4
19
what operation: add
2 4 1
what operation: send to
2 4
16
what operation: shut down
2 4
what operation: send to
2 4
19
what operation: updated
2 4 1
what operation: send to
2 4
16
"""


# simulates a heap
class priority_queue:
    def __init__(self):
        self.tot = 0
        self.heap = [0] * 1

    # the "sorting" process of a node moving up the binary tree
    def move_up(self, p):
        if p <= 1:
            return
        if self.heap[p] < self.heap[p >> 1]:
            tmp = self.heap[p]
            self.heap[p] = self.heap[p >> 1]
            self.heap[p >> 1] = tmp

    # push an element into the priority_queue
    def push(self, x):
        self.tot += 1
        self.heap.append(x)
        self.move_up(self.tot)

    # the "sorting" process of a node moving down the binary tree
    def move_down(self, p):
        son = p << 1
        if son > self.tot:
            return
        if son | 1 <= self.tot and self.heap[son | 1] > self.heap[son]:
            son |= 1
        if self.heap[p] > self.heap[son]:
            tmp = self.heap[son]
            self.heap[son] = self.heap[p]
            self.heap[p] = tmp

    # remove the smallest element in priority_queue
    def pop(self):
        tmp = self.heap[self.tot]
        self.heap[self.tot] = self.heap[1]
        self.heap[1] = tmp
        self.tot -= 1
        self.move_down(1)
        self.heap.remove(self.heap[self.tot + 1])

    # get the top element in the priority_queue
    def top(self):
        return self.heap[1]

    # check if the priority_queue is empty
    def empty(self):
        return self.tot <= 0


# get the position of the left son
def lc(rt):
    return rt << 1


# get the position of the right son
def rc(rt):
    return rt << 1 | 1


# number of people
n = int(input("how many total people on the internet are there? "))


class segment_tree:
    def __init__(self):
        # st is the segment tree
        self.st = [0 for i in range((n << 2) + 10)]
        # stores marked changes for interval update
        self.lazy = [0 for i in range((n << 2) + 10)]

    # calculate value of father based on son
    def push_up(self, rt):
        self.st[rt] = self.st[lc(rt)] + self.st[rc(rt)]

    # bring the lazy value down for range update
    def push_down(self, rt, l, r, mid):
        self.lazy[lc(rt)] += self.lazy[rt]
        self.lazy[rc(rt)] += self.lazy[rt]
        self.st[lc(rt)] += (mid - l + 1) * self.lazy[rt]
        self.st[rc(rt)] += (r - mid) * self.lazy[rt]
        self.lazy[rt] = 0

    # build the tree
    def build(self, rt, l, r):
        if l == r:
            self.st[rt] = dist[l]
            return

        mid = (l + r) >> 1
        self.build(lc(rt), l, mid)
        self.build(rc(rt), mid + 1, r)
        self.push_up(rt)

    # interval update
    def update(self, rt, l, r, x, y, val):
        if l == x and y == r:
            self.st[rt] += (r - l + 1) * val
            self.lazy[rt] += val
            return

        mid = (l + r) >> 1
        self.push_down(rt, l, r, mid)
        if y <= mid:
            self.update(lc(rt), l, mid, x, y, val)
        elif x > mid:
            self.update(rc(rt), mid + 1, r, x, y, val)
        else:
            self.update(lc(rt), l, mid, x, mid, val), self.update(rc(rt), mid + 1, r, mid + 1, y, val)
        self.push_up(rt)

    # ask for the sum for a range
    def query(self, rt, l, r, x, y):
        if l == x and y == r:
            return self.st[rt]

        mid = (l + r) >> 1
        self.push_down(rt, l, r, mid)
        if y <= mid:
            return self.query(lc(rt), l, mid, x, y)
        elif x > mid:
            return self.query(rc(rt), mid + 1, r, x, y)
        else:
            return self.query(lc(rt), l, mid, x, mid) + self.query(rc(rt), mid + 1, r, mid + 1, y)


# set INF as the default value for the distance before dijkstra
INF = 0x7f7f7f7f7f7f7f7f
pq = priority_queue()
# m is the number of path, the path are undirected
m = int(input("how many path ways there are on the internet? "))
# store the shortest path from the user to all the other people
dist = [0 for i in range(n + 10)]
# store the position of the user
user = int(input("which person is the user? "))
# mark that a node has been visited
vis = [False for i in range(n + 10)]
# store the graph
e = [[] for i in range(n + 10)]

# stores the shortest path
internet = segment_tree()
# stores how much quicker is the device of some people after updated operation
local = segment_tree()


# calculate dijkstra
def dij():
    # initialize the priority_queue by pushing in the starting value, this case the user position
    pq.push((0, user))
    global dist
    global vis
    dist = [INF] * (n + 10)
    dist[user] = 0
    vis = [False] * (n + 10)
    while not priority_queue.empty(pq):
        cur = priority_queue.top(pq)
        priority_queue.pop(pq)
        vis[cur[1]] = True
        for v in e[cur[1]]:
            if vis[v[0]]:
                continue
            # Since there are no negative time for the paths, we can immediately set it as the minimum dist
            # if there is negative time then I should use SPFA here
            if dist[v[0]] > dist[cur[1]] + v[1]:
                dist[v[0]] = dist[cur[1]] + v[1]
                pq.push((dist[v[0]], v[0]))
    # build internet segment tree
    segment_tree.build(internet, 1, 1, n)


def main():
    print("please enter three numbers to indicate the two points the path is connecting as well as the length of the "
          "path ")
    for i in range(m):
        u, v, w = map(int, input().split())
        # store the graph this way instead of matrix saves memory
        e[u].append((v, w))
        e[v].append((u, w))

    dij()
    q = int(input("how many operation will be provided "))
    print("add for add edge ")
    print("shut down for removing edge ")
    print("send to indicate send to everyone along l to r ")
    print("updated to indicate that people from l to r have updated their program and it takes w seconds less to "
          "receive something ")
    while q > 0:
        opt = input("what operation: ")
        q -= 1
        if opt == "add":
            u, v, w = map(int, input().split())
            e[u].append((v, w))
            e[v].append((u, w))
            dij()
        elif opt == "shut down":
            u, v = map(int, input().split())
            for i in range(len(e[u])):
                if e[u][i][0] == v:
                    e[u].remove(e[u][i])
            for i in range(len(e[v])):
                if e[v][i][0] == u:
                    e[v].remove(e[v][i])
            dij()
        elif opt == "send to":
            l, r = map(int, input().split())
            ans = segment_tree.query(internet, 1, 1, n, l, r) + segment_tree.query(local, 1, 1, n, l, r)
            if ans > INF:
                print("not possible")
            else:
                print(ans)
        elif opt == "updated":
            l, r, val = map(int, input().split())
            segment_tree.update(local, 1, 1, n, l, r, -val)


if __name__ == "__main__":
    main()
