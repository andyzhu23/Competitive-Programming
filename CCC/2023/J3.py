n = int(input())
s = []
for i in range(n): 
    s.append(input())
mx = 0
ans = []
for i in range(5):
    cnt = 0
    for j in range(n):
        if s[j][i] == 'Y': 
            cnt += 1
    if cnt > mx:
        mx = cnt
        ans = [i + 1]
    elif cnt == mx: 
        ans.append(i + 1)
for i in range(len(ans) - 1): 
    print(ans[i], end=',')
print(ans[len(ans) - 1])
