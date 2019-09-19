import sys


def cal_degree(data):
    initial = int(data[0])
    first = int(data[1])
    second = int(data[2])
    third = int(data[3])

    sum = 1080

    sum += ((initial - first + 40) % 40 + (second - first + 40) % 40 + (second - third + 40) % 40) * 9

    return sum

if __name__ == '__main__':
    input_str = sys.stdin.read()
    lines = input_str.split('\n')
    lines = lines[:-1]

    data = []
    for line in lines:
        data.append(line.split(' '))
    
    for t in data:
        if t[0] != '0' or t[1] != '0' or t[2] != '0' or t[3] != '0':
            print(cal_degree(t))
