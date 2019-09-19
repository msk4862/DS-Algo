import math

t = int(input())
for  _ in range(t):
    m, n= map(int, input().split(' '))

    m -= 2
    n -= 2

    print(math.ceil(m/3) * math.ceil(n/3))