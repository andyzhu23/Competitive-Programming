from collections import deque

inputs = [int(x) for x in input().split()]

tests = []
amount = 0
for i in range(inputs[0]):
    temp = input().split()
    temp = [int(x) for x in temp][::-1]
    amount += temp[1]
    tests.append(temp)

tests = sorted(tests)
tests = deque(tests)
amount = (inputs[2] * inputs[0]) - amount

time = 0
while amount > 0:
    if(tests[0][1] >= inputs[1]):
        tests.popleft()
    else:
        timesCan = inputs[1] - tests[0][1] #amount of marks you can get on specific test

        if(amount > timesCan):
            time += tests[0][0] * timesCan
            tests[0][1] += 1 * timesCan
            amount -= 1 * timesCan
        else:
            time += tests[0][0] * amount
            tests[0][1] += 1 * amount
            amount -= 1 * amount

print(time)
