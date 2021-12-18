import sys
input = sys.stdin.readline

roads = []
queue = []
checked = []
connections = {}
bomb = 0
last = "A"

while True:
    temp = str(input()).strip("\n")
    if temp == "**":
        break
    elif "A" in temp:
        queue.append(temp)
        checked.append(temp)
    roads.append(temp)

def newGraph(stop):
    for road in roads:
        connections[road[1]] = []
        connections[road[0]] = []
    for road in roads:
        if road != stop:
            connections[road[0]].append(road[1])
            connections[road[1]].append(road[0])

def search(item):
  if not item in checked:
    checked.append(item)
    for node in connections[item]:
      search(node)

for road in roads:
    checked = []
    newGraph(road)
    search("A")
    if not "B" in checked:
         print(road)
         bomb+=1
print("There are %d disconnecting roads." % bomb)
