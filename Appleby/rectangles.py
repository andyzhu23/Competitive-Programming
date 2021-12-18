num = int(input())
positions = []
max_area = 0
for i in range(num):
    pos = input()
    pos = pos.split()
    pos = (int(pos[0]), int(pos[1]))
    positions.append(pos)

for pos1 in positions:
    x1, y1 = pos1
    for pos2 in positions:
        x2, y2 = pos2
        if x1 == x2 and pos2 is not pos1:
            for pos3 in positions:
                x3, y3 = pos3
                if y1 == y3 and pos3 is not pos1:
                    if (x3, y2) in positions:
                        area = abs((x3-x1) * (y2-y1))
                        max_area = max(max_area, area)
print(max_area)
