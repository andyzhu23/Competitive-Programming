def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b, c = [0 for i in range(n)], [0 for i in range(n)]
    b[0], c[-1] = 1, 1
    for i in range(1, n):
        b[i] = b[i - 1]
        if a[i] == a[0]: b[i] += 1
    for i in range(n - 2, -1, -1):
        c[i] = c[i + 1]
        if a[i] == a[-1]: c[i] += 1
    ans = False
    for i in range(n - 1):
        if b[i] >= k:
            ans = c[i + 1] >= k
            break
    if a[0] == a[-1]: ans = b[-1] >= k
    if ans: print("YES")
    else: print("NO")

t = int(input())

for i in range(t):
    solve()