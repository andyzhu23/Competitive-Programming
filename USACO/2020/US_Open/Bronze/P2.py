n = int(input())
a = []
ans = 0
for i in range(n):
    x, i = map(int, input().split())
    a.append((x, i))
    ans += i

a = sorted(a)
mn = 0x3f3f3f3f
for i in range(1, n):
    if a[i - 1][1] != a[i][1]:
        mn = min(mn, a[i][0] - a[i - 1][0])

for i in range(1, n):
    if a[i - 1][1] == 1 and a[i][1] == 1 and a[i][0] - a[i - 1][0] < mn:
        ans -= 1

print(ans)
