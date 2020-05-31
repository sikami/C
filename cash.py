a = [25,10,5,1]

_input = input('Change owed:')

while len(_input) == 0 or _input.startswith('-') or _input.isalpha() == True:
    _input = input('Change owed:')

_float = float(_input)
count = None
coins = 0

while _float > 0:
    #if user input is float, reverts user input to float and times 100
    if type(_input) == str:
        _float = float(_input) * 100
    for i in a[::1]:
        if _float >= float(i):
            count = _float/float(i)
            coins = coins + int(count)
            _float = _float - (int(count)*i)
    print(int(coins))
