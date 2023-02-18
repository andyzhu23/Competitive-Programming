d = {
    "Poblano" : 1500,
    "Mirasol" : 6000,
    "Serrano" : 15500,
    "Cayenne" : 40000,
    "Thai" : 75000,
    "Habanero" : 125000,
}
n = int(input())
ans = 0
for i in range(n):
    x = input()
    ans += d[x]
print(ans)