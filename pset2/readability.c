#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);
float letters_per_word(string input);
float sentences_per_word(string input);
int calc_index(string input);

int main(void)
{
    string input = get_string("text:");
    int index = calc_index(input);
    
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string input)
{
    int s = strlen(input);    
    int letters = 0;
    int t = 0;
    for (int i = 0; i < s; i++)
    {
        if (isspace(input[i]) == 0 && isdigit(input[i]) == 0 && ispunct(input[i]) == 0)
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string input)
{
    int s = strlen(input);    
    int words = 0;
    int t = 0;
    for (int i = 0; i < s; i++)
    {
        if (isspace(input[i]) == 0 && (isspace(input[i + 1]) != 0 || input[i + 1] == '\0'))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string input)
{
    int s = strlen(input);    
    int sentences = 0;

    for (int i = 0; i < s; i++)
    {
        if (isspace(input[i]) == 0 && (input[i + 1] == 33 || input[i + 1] == 46 || input[i + 1] == 63))
        {
            sentences++;
        }
    }
    return sentences;
}

float letters_per_word(string input)
{
    int letters = count_letters(input);
    int words = count_words(input);
    float avg = (float)(letters * 100) / (float) words;
    return avg;

}

float sentences_per_word(string input)
{
    int sentences = count_sentences(input);
    int words = count_words(input);
    
    float avg = (float)(sentences * 100) / (float) words;
    
    return avg;
}


int calc_index(string input)
{
    float l = letters_per_word(input);
    float s = sentences_per_word(input);
    float index = 0.0588 * l - 0.296 * s - 15.8;

    return round(index);
}
