from sys import argv

if __name__ == '__main__':

    if len(argv) == 1 or len(argv) != 2:
        print('Usage: python bleep.py dictionary')
        exit(1)

    _file = argv[1]
    length = len(argv)

    ban = set()
    censored = list()
    sentence = input('What message would you like to censor?\n')


    with open(_file) as file:
        _list = file.read()
        words = _list.split()

        for word in words:
            ban.add(word)

    words = sentence.split()
    for i in words:
        new = i.lower()

        if new in ban:
            new = '*' * len(new)
        else:
            new = i

        censored.append(new)

print(' '.join(censored))
