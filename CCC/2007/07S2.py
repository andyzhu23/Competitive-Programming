snowflakes = int(input())
found = set()

def findLowest(a):
    lowestFound = a
    current = list(map(int, a[::]))
    for i in range(6):
        current = current[1:] + [current[0]]

        foundLower = False
        for i in range(len(current)):
            if(int(lowestFound[i]) < current[i]):
                break
            if(int(lowestFound[i]) > current[i]):
                foundLower = True
                lowestFound = current[::]
                break
    
    current = current[::-1]
    for i in range(6):
        current = current[1:] + [current[0]]

        foundLower = False
        for i in range(len(current)):
            if(int(lowestFound[i]) < current[i]):
                break
            if(int(lowestFound[i]) > current[i]):
                foundLower = True
                lowestFound = current[::]
                break


    return list(map(str, lowestFound))

for i in range(snowflakes):
    a = findLowest(input().split(" "))
    found.add(" ".join(a))

if(len(found) < snowflakes): print("Twin snowflakes found.")
else: print("No two snowflakes are alike.")
