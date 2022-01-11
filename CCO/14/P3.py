mod = int(1e9 + 7)
n, w, m = map(int, input().split())
e = [[] for i in range(n + 2)]
dp = [[[0 for k in range(2)] for j in range(w + 2)] for i in range(n + 2)]
cnt = [0 for i in range(n + 2)]
for i in range(m):
    a,b,c = list(input().split())
    b = int(b)
    c = int(c)
    cnt[c] += 1
    e[b].append((c, a))
    e[c].append((b, a))
for i in range(1, n + 1):
    if cnt[i] == 0:
        e[0].append((i, 'D'))

def dfs(u, fa):
    dp[u][0][0] = 1
    dp[u][1][1] = 1
    for v, x in e[u]:
        if v == fa:
            continue
        dfs(v, u)
        for i in range(w, -1, -1):
            ans0 = 0
            ans1 = 0
            for j in range(i + 1):
                ans0 = (ans0 + dp[u][i - j][0] * (dp[v][j][1] + dp[v][j][0])) % mod
                if x == 'A':
                    ans1 = (ans1 + dp[u][i - j][1] * dp[v][j][0]) % mod
                else:
                    ans1 = (ans1 + dp[u][i - j][1] * dp[v][j][1]) % mod
            dp[u][i][0] = ans0
            dp[u][i][1] = ans1
dfs(0, -1)

print(dp[0][w][0])
