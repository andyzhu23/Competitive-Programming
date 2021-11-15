n, m = map(int, input().split())
f = []
ans = 0
for i in range(n):
    f.append(list(map(int, input().split())))
f.sort(key=lambda i: i[0])
for i in f:
    if m <= i[1]:
        ans += m * i[0]
        break
    else:
        ans += i[1] * i[0]
        m -= i[1]
print(ans)
