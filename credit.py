#!/usr/bin/python3

def addproduct(j):
    j = j*2
    if j > 9 :
        j = str(j)
        j = int(j[0]) + int(j[1])
    double.append(j)
    
 
def credit_type(user_input):
    if len(user_input) == 15 and user_input.startswith('34') or len(user_input) == 15 and user_input.startswith('37'):
        print('AMEX')
    elif len(user_input) == 16 and (user_input.startswith('51') or user_input.startswith('52') or user_input.startswith('53') or user_input.startswith('54') or user_input.startswith('55')):
        print('MASTERCARD')
    elif (len(user_input) == 13 or len(user_input) == 16) and user_input.startswith('4'):
        print('VISA')
    else:
        print('OTHER CARD')

if __name__ == '__main__':
    dash = None
    while dash == None or dash > 0 or user_input.isalpha() == True or len(user_input) == 0:
        user_input = input('Number:')
        dash = user_input.find('-')

        if len(user_input) > 16:
            print('INVALID')
            break

    number = []
    double = []
    new_number = []
    new = user_input[-1::-2]
    latest = user_input[0::2]

    if len(user_input) == 15:
        latest = user_input[1::2]
        new = user_input[0::2]
    if user_input.find(" ") == True:
        user_input.replace(" ", "")
    for i in new:
        number.append(int(i))
    for j in latest:
        new_number.append(int(j))
    for j in new_number:
        addproduct(j)

add = sum(number + double)
print(add)
if add % 10 == 0:  
    credit_type(user_input)
else: 
    print('invalid')
