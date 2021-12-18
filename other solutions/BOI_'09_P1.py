mport math

def find_next_mine():
    min_angle = 10
    min_mine = current
    for mine in mines:
        if mine != current:
            angle = math.pi/2 - math.atan2(mine[1] - current[1], mine[0] - current[0])
            if turned:
                angle += math.pi
            angle %= 2 * math.pi
            if angle < min_angle:
                min_mine = mine
                min_angle = angle
    return min_mine


n, r = map(int, input().split())
mines = [tuple(map(int, input().split())) for i in range(n)]

start_point = min(mines)
turn_point = max(mines)
current = start_point
dist = 0
turned = False

while True:
    next_mine = find_next_mine()
    dist += math.sqrt((next_mine[0] - current[0])**2 + (next_mine[1] - current[1])**2)
    if next_mine == start_point:
        break
    if next_mine == turn_point:
        turned = True
    current = next_mine

print(dist + 2 * math.pi * r)
