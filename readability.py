def sentence(x):
    count_sentence = 0
    for i in x:
        if i == '.' or i == '!' or i == '?' :
            count_sentence += 1
    return count_sentence

def letters(x):
    small = range(97,123)
    big = range(65, 91)
    letter = 0
    for i in x:
        if ord(i) in small or ord(i) in big:
            letter +=1
        else:
            continue
    return letter

def words(x):
    count_words = 1
    for i in x:
        if i == ' ':
            count_words += 1
    return count_words

def L(x):
    a = letters(x) / words(x) * 100.0
    return a

def S(x):
    b = sentence(x) / words(x) *100.0
    return b

def formula(L,S):
    form = 0.0588 * L - 0.296 * S - 15.8
    return round(form)

if __name__  == '__main__':
    string = input('Text: ')
    x = formula(L(string),S(string))
    if x < 0:
        print('Before Grade 1')
    elif x > 16:
        print('Grade 16+')
    else:
        print('Grade', x)