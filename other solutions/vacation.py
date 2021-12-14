n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))
f = [[0 for i in range(3)] for i in range(n+1)]
f[0][0] = arr[0][0]
f[0][1] = arr[0][1]
f[0][2] = arr[0][2]
for day in range(1, n):
    f[day][0] = arr[day][0] + max(f[day-1][1], f[day-1][2])
    f[day][1] = arr[day][1] + max(f[day-1][0], f[day-1][2])
    f[day][2] = arr[day][2] + max(f[day-1][0], f[day-1][1])
print(max(f[n-1]))
