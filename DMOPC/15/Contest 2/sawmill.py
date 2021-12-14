a = int(input())
energy = list(map(int, input().split()))
energy.sort()
logs = list(map(int, input().split()))
logs.sort(reverse = True)
total = 0
for i in range(a):
    total += (energy[i]*logs[i])
print(total)
