
def main(num):

    num_words = {'1': 'one', '2': 'two', '3':'three','4': 'four','5':'five','6':'six','7':'seven','8':'eight',
    '9':'nine','11':'eleven','12':'twelve','13': 'thirteen','14':'fourteen','15':'fifteen','16':'sixteen',
    '17':'seventeen','18':'eighteen','19':'nineteen','10':'ten','20':'twenty','30':'thirty','40':'forty',
    '50':'fifty','60':'sixty','70':'seventy','80':'eighty','90':'ninety'} 
    
    words=''

    while int(num) > 0:
        word_len = len(num)

        if word_len == 1:
            words += num_words[num]
            break

        elif word_len == 2:
            if(num[0] == '1'):
                words += num_words[num]
                break
            else:
                words += num_words[num[0]+'0']
            num = str(int(num)%10)

        elif word_len == 3:
            words += num_words[num[0]]
            words += ' hundred'
            num = str(int(num)%100)
            
            if(num != '0'):
                words+=' and'
                
        elif word_len == 4:
            words += num_words[num[0]]
            words += ' thousand'

            num = str(int(num)%1000)

    return len(words.replace(' ', ''))
    

if __name__ == '__main__':
    num = (input())

    sum = 0

    for i in range(1, int(num)+1):
        sum += main(str(i))

    print(sum)