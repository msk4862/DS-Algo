def isPalind(num):
    for i in range(len(num)//2):
        if num[i] != num[-(i+1)]:
            return False
    return True

def largestPalind(n):
    max_num = int('9'*n)
    min_num = int('1'+'0'*(n-1))

    largest = 0
    
    for i in range(max_num, min_num, -1):
        for j in range(max_num, min_num, -1):
            prod = i*j
            if(largest == 0 or largest<prod):
                if isPalind(str(prod)):
                    largest= prod

    return largest

if __name__ == '__main__':
    n = int(input('Enter no. of digit:'))
    print(largestPalind(n))