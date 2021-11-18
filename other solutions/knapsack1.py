n, w = map(int, input().split())
dp = [0 for i in range(w + 1)]
for i in range(n):
    a, b = map(int, input().split())
    for j in range(w, a - 1, -1):
        dp[j] = max(dp[j], dp[j - a] + b)
print(dp[w])
