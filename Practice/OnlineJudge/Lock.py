import sys

degree = 360//40

def cal_degree(data):
    initial = int(data[0])
    first = int(data[1])
    second = int(data[2])
    third = int(data[3])

    sum = 720
    #clockwise
    if first >= initial :
        sum += abs(first-initial)*degree
    else:
        sum += abs(40 -first +initial)*degree
    
    sum += 360

    # anti-clockwise
    if second <= first :
        sum += abs(first -second)*degree
    else:
        sum += abs(first + 40-second)*degree
    
    #clockwise
    if third >= second :
        sum += abs(third-second)*degree
    else:
        sum += abs(40 -third +first)*degree

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
