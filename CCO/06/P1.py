import math
a = int(input())
places = []
for i in range(a):
    x = input().split()
    places.append(x)

coordinates = []
for p in places:
    coordinates.append(float(p[1]))
coordinates.sort()

total = 0
differences = []
for c in range(a-1):
    differences.append(coordinates[c+1]-coordinates[c])
coordinates[-1] -=360
differences.append(coordinates[0]-coordinates[-1])
print(math.ceil(4320*(360-max(differences))/360))
