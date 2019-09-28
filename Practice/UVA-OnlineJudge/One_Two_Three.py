n = int(input())
for _ in range(n):
    t = input()
    if len(t) == 5:
        print(3)
    else:
        num = 1 if (('n' in t) and ('e' in t)) or (('o' in t) and ('n' in t)) or (('o' in t) and ('e' in t)) else 2
        print(num)
    