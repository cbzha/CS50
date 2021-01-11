from cs50 import get_string
import string


def main():
    input = get_string("text:")
    index = calc_index(input)
    if (index < 0):
        print("Before Grade 1")
    elif (index >= 16):
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def count_letters(input):
    letters = 0
    for i in range(len(input)):
        if not(input[i].isspace()) and not(input[i].isdigit()) and not (input[i] in string.punctuation):
            letters += 1
    return letters


def count_words(input):
    words = 0
    for i in range(len(input) - 1):
        if not(input[i].isspace()) and (input[i + 1].isspace() or i + 1 == len(input) - 1):
            words += 1
    return words


def count_sentences(input):
    sentences = 0
    for i in range(len(input) - 1):
        if not(input[i].isspace()) and (input[i+1] in '!' or input[i+1] in '.' or input[i+1] in '?'):
            sentences += 1
    return sentences


def letters_per_word(input):
    letters = count_letters(input)
    words = count_words(input)
    avg = (letters * 100) / words

    return avg


def sentences_per_word(input):
    sentences = count_sentences(input)
    words = count_words(input)
    avg = (sentences * 100) / words

    return avg


def calc_index(input):
    l = letters_per_word(input)
    s = sentences_per_word(input)
    index = 0.0588 * l - 0.296 * s - 15.8

    return round(index)


main()