#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int words(string x, int len);
int letter(string x, int len);
int sentence(string x, int len);


int main(void)
{
    //ask user input store as string, calculate the length of string
    string s = get_string("Text: ");
    int length = strlen(s);

    //calculate words, letters, sentences
    int W = words(s, length);
    int L = letter(s, length);
    int S = sentence(s, length);

    //calculate the average letter and sentence
    float _L = L / (float)W * 100;
    float _S = S / (float)W * 100;

    //input the result of average letter and sentence into formula
    float result = 0.0588 * _L  - 0.296 * _S - 15.8;

    //check if grade is within requirement, then print appropriate grade
    if (round(result) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (round(result) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", round(result));
    }
}



//functions to calculate how many words in the string
int words(string x, int len)
{
    int counter = 1;
    for (int i = 0; i < len; i++)
    {
        if (x[i] == ' ')
        {
            counter += 1;
        }
    }
    return counter;
}

//function to calculate how many letters in the string
int letter(string x, int len)
{
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(x[i]))
        {
            counter += 1;
        }
    }
    return counter;
}

//function to calculate how many sentences in the string
int sentence(string x, int len)
{
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (x[i] == '.' || x[i] == '?' || x[i] == '!')
        {
            counter += 1;
        }
    }
    return counter;
}