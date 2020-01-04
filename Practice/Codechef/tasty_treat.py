t = int(input())

while t != 0:
    a = input()
    b = input()
    
    cost = 0
    
    for ing in b:
        if b.count(ing) > a.count(ing):
            cost += (b.count(ing)-a.count(ing))
        a = a.replace(ing, '')
        b = b.replace(ing, '')
    print(cost)
    t-=1
    