t = int(input())

while t!=0:
    mirror = {'1': '1', '2': '7', '3':'8', '4':'5', '6':'9', '7':'2','8':'3','5':'4','9':'6'}
    n = input()
    check = True
    if '0' in n:
        print('false')
    else:
        for i in range(len(n)//2):
            if mirror[n[i]] != n[-(i+1)]:
                check = False
                break
            
        if check == True:
            print('true')
        else:
            print('false')
            
    t -= 1    