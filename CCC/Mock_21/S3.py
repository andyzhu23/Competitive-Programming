n, k = map(int, input().split())

a = []
cnt = {}

for i in range(n):
    cur = int(input())
    if(cur > k):
        continue
    if cur not in cnt:
        cnt[cur] = 0
    cnt[cur] += 1
    a.append(cur)

stk = [0 for i in range(k + 10)]
vis = {}
len = 0
for i in a:
    if i not in vis:
        while len > 0 and stk[len] > i and cnt[stk[len]] > 0:
            del vis[stk[len]]
            len -= 1
        len += 1
        stk[len] = i
    vis[i] = True
    cnt[i] -= 1

for i in range(1, len):
    print(stk[i], end=' ')
print(stk[len])
