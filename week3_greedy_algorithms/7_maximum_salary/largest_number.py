#Uses python3


import sys

def is_max(maxDigit, digit):
	if len(maxDigit)== len(digit):
		return int(maxDigit) < int(digit)
	else: 
		a1 = int(digit + maxDigit)
		a2 = int(maxDigit + digit)
		if a1 > a2:
			return True
		else:
  			return False

def largest_number(a):

	res = ""

	while len(a) >= 1:
		maxDigit = a[0]
		for digit in a:
			if is_max(maxDigit, digit):
				maxDigit = digit
		a.remove(maxDigit)
		res += maxDigit
	return res

if __name__ == '__main__':
    input = sys.stdin.read()
    data = input.split()
    a = data[1:]
    print(largest_number(a))
    
