import sys

def TEXT_conv(text):
    q = '"'
    new_text = ''
    check = 1
    for x in text:
        if x is q:
            if check % 2 != 0:
                new_text += '``'
            else:
                new_text += "''"
            check+=1
        else:
            new_text += x
    return new_text

if __name__ == '__main__':
    input_str = sys.stdin.read()
    print(TEXT_conv(input_str))