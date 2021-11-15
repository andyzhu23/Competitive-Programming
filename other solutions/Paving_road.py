n = int(input())
d = list(map(int, input().split()))
d.insert(0, 0)
ans = 0
for i in range(1, n + 1):
    ans += max(0, d[i] - d[i - 1])
print(ans)
