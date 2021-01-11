from sys import argv
import csv


def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    temp = load_csv(argv[1])
    list_strs = load_dna(argv[2], temp)
    print(match(list_strs))


def load_csv(name):
    global spamreader
    csvfile = open(name, newline='')
    spamreader = csv.reader(csvfile, delimiter=',')
    for row in spamreader:
        return row[1:]


def load_dna(name, strs):
    list_strs = []
    for x in strs:
        count = 0
        biggest = 0
        with open(name, 'r') as f:
            data = f.read()
        size = len(x)
        i = 0
        while i < len(data):
            if data[i:i+size] == x:
                count += 1
                if count > biggest:
                    biggest = count
                i += size
                continue
            count = 0
            i += 1
        list_strs.append(str(biggest))
    return list_strs


def match(list_strs):
    for row in spamreader:
        if row[1:] == list_strs:
            return row[0]
    return "No match"


main()