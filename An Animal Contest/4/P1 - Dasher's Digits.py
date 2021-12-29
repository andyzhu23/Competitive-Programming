n, m = map(int, input().split())
x = input()
a = list(map(int, input().split()))

mcv = 0
pos0 = 0
for i in range(m):
    if a[i] >= mcv:
        mcv = a[i]
        pos0 = i + 1

pos = 0
for i in range(n):
    if x[i] == "0":
        pos += 1
        if pos == pos0:
            pos = i + 1
            break 

x = x.replace("0", "") 
pos -= pos0

print(x[pos:n] + x[:pos])