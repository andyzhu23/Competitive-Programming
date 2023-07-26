
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = sorted(a)
    ans = True
    for i in range(n):
        ans &= a[i] % 2 == b[i] % 2
    print("YES" if ans else "NO")

t = int(input())
for i in range(t):
    solve()