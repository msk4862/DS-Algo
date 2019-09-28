t = int(input())
amount = 0
for _ in range(t):
    
    line = input()

    if ' ' in line:
        op, money = line.split(' ')
        amount += int(money)
    else:
        print(amount)
        