n, r, s = map(int, input().split())
for i in range(n):
    mn = 0x3f3f3f3f
    mx = 0
    for j in range(r):
        x = input()
        for c in x:
            if c == '#':
                mx = max(mx, j)
                mn = min(mn, j)
    print(mx - mn)
