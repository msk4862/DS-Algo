import math

def leap(y):
    isL = False
    if y%4==0:
        isL = True
        if y%100==0:
            isL = False
        if y%400 == 0:
            isL = True
    return isL

def calc(y, m, d):
    days = [16, 0, 16, 31, 16, 31, 16, 16, 31, 16, 31, 16]
    if m == 2:
        days[1] = 15 if leap(y) else 30
    meds = days[m-1] - math.floor(d/2)
    return meds

t = int(input())
for _ in  range(t):
    y, m, d = input().split(':')
    y = int(y)
    m = int(m)
    d = int(d)
    print(calc(y,m,d))