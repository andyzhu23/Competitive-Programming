n, m = map(int, input().split())
ans = 0

def gcd(a, b):
    if a * b == 0: return a + b
    return gcd(b, a % b)

for i in range(0, n + 1):
    for j in range(0, m + 1):
        if i == 0 and j == 0: continue
        if i == 0 or j == 0: ans += (gcd(i, j) - 1) * (n + 1 - i) * (m + 1 - j)
        else: ans += (gcd(i, j) - 1) * (n + 1 - i) * (m + 1 - j) << 1
print(((n + 1) * (m + 1)) * ((n + 1) * (m + 1) - 1) * ((n + 1) * (m + 1) - 2) // 6 - ans)
