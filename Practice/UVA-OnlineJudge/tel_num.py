def simplify_tel(tel):

    alpha_map = {'A':'2', 'B':'2', 'C':'2', 'D':'3', 'E':'3', 'F':'3', 'G':'4', 'H':'4', 'I':'4',
                'J':'5', 'K':'5', 'L':'5', 'M':'6', 'N':'6', 'O':'6', 'P':'7', 'R':'7', 'S':'7',
                'T':'8', 'U':'8', 'V':'8', 'W':'9', 'X':'9', 'Y':'9'}

    tel = tel.replace('-', '')
    if tel.isdigit():
        return tel
    else:
        tel_n = ''
        for i in range(len(tel)):
            if tel[i].isalpha():
                tel_n += alpha_map[tel[i]]
            else:
                tel_n += tel[i]
        return tel_n


def std_tel(tel):
    c= 0
    simp = ''
    for i in tel:
        if c == 3:
            simp +='-'
            simp += i
        else:
            simp += i
        c += 1
    return simp

t= int(input())

while t != 0:
    input()
    n = int(input())

    tel_dict = {}

    duplicates = False

    for _ in range(n):
        tele = input()
        num = simplify_tel(tele)
        if num in tel_dict:
            duplicates = True
            tel_dict[num] +=1
        else:
            tel_dict[num] = 1
    
    if not duplicates:
        print('No duplicates.')
    else:
        for tel in sorted(tel_dict):
            if tel_dict[tel] != 1:
                print(std_tel(tel).strip(), tel_dict[tel])
        
    print()
    t -= 1