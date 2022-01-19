import sys
from collections import deque

n = int(sys.stdin.readline().strip())
s = sys.stdin.readline().strip()
dq = deque()
for c in s:
    if len(dq) == 0: dq.append(c)
    elif ord(dq[0]) >= ord(c): dq.appendleft(c)
    else: dq.append(c)
for i in dq:
    print(i, end='')
print()
