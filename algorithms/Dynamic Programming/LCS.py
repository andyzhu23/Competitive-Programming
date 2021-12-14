s = input()
t = input()
ls = len(s)
lt = len(t)
 
 
dp = [[0 for i in range(lt + 1)] for j in range(ls + 1)]
 
for i in range(ls):
    for j in range(lt):
        if s[i] == t[j]:
            dp[i + 1][j + 1] = dp[i][j] + 1
        else:
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j])
 
i = ls - 1
j = lt - 1
answer = ''
while (0 <= i) & (0 <= j):
    if s[i] == t[j]:
        answer += s[i]
        i -= 1
        j -= 1
    elif dp[i + 1][j + 1] == dp[i + 1][j]:
        j -= 1
    else:
        i -= 1
print(answer[::-1])
