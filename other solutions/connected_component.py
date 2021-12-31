n = int(input())
f = [i for i in range(n + 1)]
vis = [False for i in range(n + 1)]
ans = [[] for i in range(n + 1)]

def Find(x):
    if x == f[x]:
        return x
    f[x] = Find(f[x])
    return f[x]

def merge(u, v):
    fu = Find(u)
    fv = Find(v)
    if fu > fv:
        f[fv] = fu
    else:
        f[fu] = fv

for i in range(n):
    a = list(map(int, input().split(' ')))
    for j in range(n):
        if a[j] == 1:
            merge(i + 1, j + 1)

for i in range(n):
    ans[Find(i + 1)].append(i + 1)
for i in range(n):
    if len(ans[Find(i + 1)]) > 0 and not vis[Find(i + 1)]:
        vis[Find(i + 1)] = True
        ans[Find(i + 1)].sort()
        for j in range(len(ans[Find(i + 1)]) - 1):
            print(ans[Find(i + 1)][j], end=' ')
        print(ans[Find(i + 1)][len(ans[Find(i + 1)]) - 1])
