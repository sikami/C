height = input('Please set the height:')
while height.isalpha() == True or int(height) < 1 or int(height) > 8:
    height = input('Please set the height:')
    continue

numbers = int(height)
number = abs(numbers)

try:
    k = range(number,0,-1)
    l = number - (number-1)
    if number > 0 or number < 9: 
        for i in k:       
            print(i * ' ', end='')
            print(l* '#')
            l +=1
except Exception as diag:
    print('Your input has to be positive integer')


    
