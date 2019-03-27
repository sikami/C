#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
  while (argc != 2)
  {
    printf("Please input a valid command line. for example: ./caesar [int]\n");
    return 1;
  }

int k = atoi(argv[1]);
string plaintext = get_string();

  int j = k % 26;
  for (int i = 0; i < strlen(plaintext); i++)
  {
    if(isalpha(plaintext[i]))
    {
      if(isupper(plaintext[i]))
      {
        if( plaintext[i] + j > 90)
        {
          printf("%c", plaintext[i] - 26 + j);
        }
        else
        {
          printf("%c", plaintext[i] + j);
        }
      }
      if(islower(plaintext[i]))
      {
        if(plaintext[i] + j > 122)
        {
          printf("%c", plaintext[i] - 26 + j);
        }
        else
        {
          printf("%c", plaintext[i] + j);
        }
      }
    }
    else
    {
      printf("%c", plaintext[i]);
    }
  }
  printf("\n");
}



