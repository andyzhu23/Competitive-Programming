def solve():
    n, m, k, h = map(int, input().split())
    a = list(map(int, input().split()))
    cnt = 0
    for x in a:
        if x % k == h % k and 0 < abs(h - x) <= (m - 1) * k:
            cnt += 1
    print(cnt)

t = int(input())
for i in range(t):
    solve()