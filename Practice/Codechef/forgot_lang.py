t = int(input())

while t>0:
    n, k= map(int, input().split(' '))
    
    forgotten = input().split(' ')
    
    modern = []
    for _ in range(k):
        modern += (input().split(' ')[1:])

    for forgot in forgotten:
        if forgot in modern:
            print('YES', end=' ')
        else:
            print('NO', end=' ')

    print()
    t-=1
