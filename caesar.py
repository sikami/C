import sys

if len(sys.argv) != 2:
    print('Usage: python caesar.py k')
    sys.exit(1)

k = sys.argv[1]
k = int(k)

small = range(97,122)
big = range(65, 90)
output = []
word = input('plaintext: ')
for i  in word:
    while k > 26:
        k = k - 26

    if ord(i) in small:
        new = ord(i) + k
        if new > 122:
            new = new - 26
    elif ord(i) in big:
        new = ord(i) + k
        if new > 90:
            new = new - 26
    else:
        new = ord(i)
    output.append(chr(new))

print('ciphertext: ', end='')
print(''.join(output))