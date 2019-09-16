import math

t = int(input())
for _ in  range(t):
    N, minX, maxX = map(int, input().split(' '))
    nn = []
    for _ in range(N):
        nn.append(list(map(int, input().split(' '))))

    ans1 = minX
    for i in range(len(nn)):
        ans1 %= 2
        ans1 = nn[i][0]*ans1 + nn[i][1]
    
    
    total = maxX-minX +1

    if total is 1:
        if ans1%2 == 0:
            print('1', '0')
        else:
            print('0', '1')
    else:
        ans2 = minX+1
        for i in range(len(nn)):
            ans2 = ans2%2
            ans2 = nn[i][0]*ans2 + nn[i][1]
        
        if minX%2==0:
            even = math.ceil(total/2)
            odd = total-even
            if ans1%2==0 and ans2%2 == 0:
                print(total,'0')
            elif ans1%2!=0 and ans2%2!= 0:
                print('0', total)
            # starting with even
            elif ans1%2==0 and ans2%2!= 0:
                print(even, odd)
            else:
                print(odd, even)
        else:
            odd = math.ceil(total/2)
            even = total-odd
            if ans1%2==0 and ans2%2 == 0:
                print(total,'0')
            elif ans1%2!=0 and ans2%2!= 0:
                print('0', total)
            # starting with even
            elif ans1%2==0 and ans2%2!= 0:
                print(odd, even)
            else:
                print(even, odd)