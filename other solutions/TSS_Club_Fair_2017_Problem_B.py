import math
import bisect
import sys
a,b = map(int, sys.stdin.readline().split())
distances = [0 for i in range (a)]

for i in range(a):
    x,y = map(int,sys.stdin.readline().split())
    distances[i] = math.sqrt(x ** 2 + y ** 2)
distances.sort()
for l in range(b):
    l = int(sys.stdin.readline())
    print(bisect.bisect_right(distances, l))
