num_patches, cherry_goal, max_weight = list(map(int, input().split())) 
num_cherries = list(map(int, input().split()))
counter = 0
branches = {}
for i in range(num_patches-1):
    p1, p2, k = list(map(int, input().split()))
    if p1 > p2:
        p1, p2 = p2, p1
    branches[p2] = [p1, num_cherries[p2-1], k]
for i in range(num_patches, 1, -1):
    branch = branches[i]
    if branch[1] >= cherry_goal and branch[2] <= max_weight:
        counter += 1
    if branch[0] != 1:
        c_branch = branches[branch[0]]
        c_branch[1] += branch[1]
        c_branch[2] += branch[2]
print(counter)
