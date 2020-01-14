import math

primeNum = []

def findPrimes(n):
    primes = [i for i in range(n)]

    primes[1] = 0

    for i in range(2, math.floor(math.sqrt(n))+1):
        if primes[i] !=0:
            j = 2
            while i*j<n:
                primes[i*j] = 0
                j+=1

    global primeNum

    for i in range(n):
        if primes[i] != 0:
            primeNum.append(primes[i])


def findCycle(n):

    # keep dividing by 10 and see if remainder is 1 (end of cycle)
    cycleSize = 0
    den, rem =1, 1
    while True:
        cycleSize+=1
        den =rem*10
        rem = den%n
        if rem == 1 or rem == 0:
            break

    return cycleSize
    

def findLargestCycle(n):

    largestCycle, num = 0, 0

    global primeNum

    for i in range(n):
        p = primeNum[i]
        if p < n:
            cycleLen = findCycle(p)
            if largestCycle < cycleLen:
                largestCycle = cycleLen
                num = primeNum[i]

    return num

if __name__ == '__main__':

    # to get the list of primes
    numRange = 10000
    findPrimes(numRange)

    n = int(input())
    print(findLargestCycle(n))
