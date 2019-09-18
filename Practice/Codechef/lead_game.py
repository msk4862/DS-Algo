import math

n = int(input())
ar = []
for _ in range(n):
    ar.append(list(map(int, input().split(' '))))

max_diff = 0
win = 0
sca, scb = 0, 0
for i in range(n):
    sca += ar[i][0]
    scb += ar[i][1]
    diff = abs(sca-scb)
    if  diff > max_diff:
        win = 1 if sca > scb else 2
        max_diff = diff

print(win, max_diff)