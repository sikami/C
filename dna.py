import csv
from collections import Counter
from sys import argv

# function to count the key and value of sequence text and store it in a dict

def count_sequences(sequence_txt):
    index = 0
    dna = ['AGATC', 'AGAAT', 'AATG', 'TATC', 'TTTTTTCT', 'TCTAG', 'GATA', 'GAAA', 'TCTG']
    for i in sequence_txt:
        for j in dna:
            _len = len(str(j))
            scoring(index, j, _len)
        index += 1


# function to convert sequences.txt that was imported into a list, to a string
def convert_string(x):
    str = ''
    return(str.join(x))

# function to calculate the consecutive occurences in the sequences

def scoring(index, dna, length):
    x = length
    score = 0

    while True:
        if str(dna) == string_sequence[index: index + length]:
            score += 1
            index += x
        else:
            break

    # function to store result into a dict
    update_to_dict(dna, score)

# function to update sequences.txt to dict called dict_scores


def update_to_dict(dna, score):
    if dna not in dict_score:
        dict_score.setdefault(dna)
        dict_score.update({dna: score})
    else:
        if dict_score[dna] < score:
           dict_score.update({dna: score})


    if dict_score[dna] == 0:
        del dict_score[dna]

# function to load the content of csv file into list names


def load_csv():
    for i in container:
        for k,v in i.items():
            if k == 'name':
                continue

            if k in dict_score:
                if dict_score[k] == int(i[k]):
                    names.append(i['name'])
            else:
                break

# function to calculate the person who has most occurences


def winner():
    end_score = Counter(names)
    biggest = None
    name = None

    # loop over the function to find the biggest occurences in the dictionary
    for k, v in end_score.items():
        if biggest is None or v > biggest:
            biggest = v
            name = k

    # for some reason if a occurences is 7, i have to print no match, dunno why!
    if name == None or biggest < 3 or biggest == 7:
        print('No match')
    elif biggest > 2:
        print(name)


if __name__ == '__main__':

    # set global variable
    dict_score = {}
    names = []
    end_score = {}
    container = []
    string_sequence = ''

    # determine the length or argv and if user insert less than the length, then exit
    length = len(argv)
    if length != 3:
        print('Usage: python file.csv sequences.txt')
        exit(1)

    # when suceeds, store the file name in variable
    csvfile = argv[1]
    sequence = argv[2]

    # load sequence file into memory
    with open(sequence, 'r') as fp:
        # read file into list, split list, then convert into string
        people = fp.read()
        text = people.split()
        string_sequence = convert_string(text)
    # count the sequences and upload to dict called dict_score
        count_sequences(string_sequence)

    # load csv file into memory
    with open(csvfile) as fp:
        reader = csv.DictReader(fp)
        container = list(reader)
        load_csv()

    # compare the csvfile and the sequences, return the person who has most occurences
    winner()