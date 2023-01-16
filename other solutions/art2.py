mod = 1 << 32
def exgcd(a, b):
    if b == 0: return 1, 1
    global mod
    x, y = exgcd(b, a % b)
    tmp = y
    y = (x - a // b * y % mod) % mod
    x = tmp
    return x, y

n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(int(input()) * exgcd(2654435761, mod)[0] % mod)

a.sort()
a = a[::-1]
ans = 0
for i in range(m): ans += a[i]
print(ans)
