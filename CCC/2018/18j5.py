n = int(input())
e = [[] for i in range(n + 1)]
for i in range(1, n + 1):
    a = list(map(int, input().split()))
    for j in range(1, len(a)):
        e[i].append(a[j])

l = 1
r = 2
q = [[0] for i in range(n + 1)]
vis = [False for i in range(n + 1)]
q[1] = (1, 1)
ans = 0x3f3f3f3f
while l < r:
    u = q[l][0]
    dist = q[l][1]
    if len(e[u]) == 0:
        ans = min(ans, dist)
    l += 1
    vis[u] = True
    for v in e[u]:
        if vis[v]:
            continue
        vis[v] = True
        q[r] = (v, dist + 1)
        r += 1

reach = True
for i in range(1, n + 1):
    if not vis[i]:
        reach = False

if reach:
    print('Y')
else:
    print('N')
print(ans)
