
def main(pow):
    num = str(2**pow)

    sum = 0
    for digit in num:
        sum += int(digit)
    
    return sum

if __name__ == '__main__':
    pow = int(input())
    print(main(pow))
