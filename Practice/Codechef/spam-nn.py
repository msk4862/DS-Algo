
dict = {}

def calc(x, nn):
    if x in  dict:
        return dict[x]    
    op = x
    for i in range(len(nn)):
        op = nn[i][0]*op + nn[i][1]
    
    dict[x] = op
    return op

def neural(minX, maxX, nn):
    spam = [0, 0]
    while minX <= maxX:
        res = calc(minX, nn)
        if res%2==0:
            #non
            spam[0] +=1
        else:
            spam[1] += 1
        minX += 1
    return spam

t = int(input())
for _ in  range(t):
    N, minX, maxX = input().split(' ')
    N = int(N)
    minX = int(minX)
    maxX = int(maxX)
    nn = []
    for _ in range(N):
        l = input().split(' ')
        nn.append([int(l[0]), int(l[1])])
    
    s = neural(minX, maxX, nn)
    print(s[0], s[1])