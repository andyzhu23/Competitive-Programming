a,b = map(int,input().split())
arr = []
for i in range(a):
    x = list(map(int,input().split()))
    arr.append(x)
n = int(input())
for i in range(n):
    m = int(input())
    arr.sort(key = lambda l:l[m-1])

for h in arr:
    for l in range(len(h)):
        h[l] = str(h[l])
    print(" ".join(h))
