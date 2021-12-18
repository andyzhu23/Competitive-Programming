import sys
N, lines = int(input()), []
for i in range(N-1):
	lines.append(list(map(int, input().split())))
adjacency = [0]*N

for i in lines:
	adjacency[i[0]-1] += 1
	adjacency[i[1]-1] += 1

print(max(adjacency)+1)
