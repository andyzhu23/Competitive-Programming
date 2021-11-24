n = int(input())
cnt = 1
while (1 << cnt) <= n:
    cnt += 1
print('1' * cnt)
