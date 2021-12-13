n, t = map(int, input().split())
probs = [list(map(int, input().split())) for i in range(n)]
arr = [0 for i in range(t + 1)]
for prob in probs:
    for i in range(t-prob[1], -1, -1):
        #if arr[i] != -1 and i + prob[1] <= t:
        arr[i + prob[1]] = max(arr[i + prob[1]], arr[i] + prob[0])
#print(arr)
print(max(arr))
