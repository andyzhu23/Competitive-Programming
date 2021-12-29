import math
import sys
input = sys.stdin.readline

def find(t, L, R):
    l = L
    r = R
    res = 0
    while l <= r:
        m = (l + r) // 2
        if t >= lcm[m]:
            res = m
            l = m + 1
        else:
            r = m - 1

    if lcm[res] == t:
        if res == n:
            return -1
        else:
            return res + 1
    else:
        return find(math.gcd(t, lcm[res]), 0, res) 

n, q = map(int, input().split())
l = list(map(int, input().split()))

lcm = [1 for i in range(n + 1)]
for i in range(n):
    g = math.gcd(lcm[i], l[i])
    lcm[i + 1] = (lcm[i] // g) * l[i]
    if lcm[i + 1] > 10**9:
        lcm[i + 1] = 10**9 + 1

for i in range(q):
    t = int(input())

    if t == 0:
        print(-1)
        continue 
    print(find(t, 0, n))