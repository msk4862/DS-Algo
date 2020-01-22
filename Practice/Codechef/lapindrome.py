# cook your dish here
t = int(input())

while t > 0:
    s = input()

    word = {}
    flag = True
    for i in range(len(s)//2):
        if s[i] in word:
            word[s[i]]+=1
        else:
            word[s[i]] = 1
            
    
    if len(s)%2==0:
        start = len(s)//2
    else:
        start = (len(s)//2)+1

    for i in range(start, len(s)):
        if s[i] in word:
            if word[s[i]] > 0:
                word[s[i]]-=1
            else:
               flag = False
               break
        else:
            flag = False
            break
    
    for i in word:
        if word[i] != 0:
            flag = False
            break
        
    if flag:
        print('YES')
    else:
        print('NO')
            
    t-=1