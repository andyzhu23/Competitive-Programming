n, k = map(int, input().split())

psa = [0] * 10005

for i in range(n):
    x = int(input())
    psa[x] += 1

for i in range(1, 10001):
    psa[i] += psa[i - 1]

ans = 0

for i in range(k + 1, 10000):
    ans = max(ans, psa[i] - psa[i - k - 1])

print(ans)
