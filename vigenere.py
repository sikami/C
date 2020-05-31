from sys import argv

def alphanumeric(key):
    alpha = False
    num = False
    for i in key:
        if i.isalpha() == True:
            alpha = True
        elif i.isnumeric() == True:
            num = True

    if alpha and num == True:
        return True

if __name__ == '__main__':

    key = argv[1]
    length = len(argv)

    if length != 2 or key.isdigit() == True or alphanumeric(key) == True:
        print('Usage: python vigenere.py k')
        exit(1)

    words = input('plaintext:')

    lowercase = range(97,123)
    uppercase = range(65,91)

    start = 0
    output = []
    new_key = []
    for i in key:
        i = ord(i)
        for l in lowercase:
            if l == i:
                new_key.append(lowercase.index(l))
        for l in uppercase:
            if l == i:
                new_key.append(uppercase.index(l))

    for word in words:
        word = ord(word)
        if word in lowercase:
            newkey = new_key[start % len(new_key)]
            new = word + newkey
            if new > 122:
                new -= 26
            start = start + 1
            new = chr(new)

        elif word in uppercase:
            new = word + new_key[start % len(new_key)]
            if new > 90:
                new -= 26
            start = start + 1
            new = chr(new)
        else:
            new = chr(word)

        output.append(new)

    print('ciphertext: ', end='')
    print(''.join(output))