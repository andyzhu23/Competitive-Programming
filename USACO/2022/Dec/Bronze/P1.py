n = int(input())
a = list(map(int, input().split()))
a = sorted(a)
mx = 0
ans = 0
for i in range(n):
    if mx < (n - i) * a[i]:
        mx = (n - i) * a[i]
        ans = a[i]
print(mx, ans)