#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int usage();
int main(int argc, string argv[])
{
  if ( argc != 2)
  {
    usage();
  }

  string key = argv[1];
  int key_len = strlen(argv[1]);
  int k = 0;

  while (k < key_len)
  {
    if(!isalpha(key[k]))
    {
      usage();
    }
    k++;
  }

  string text = get_string();
  int text_len = strlen(text);
  int i, j;
  for (i = 0; i < text_len; i++, k++)
  {
    j = (k % key_len);
    if(isalpha(text[i]))
    {
      if(isupper(text[i]))
      {
        if(text[i] + toupper(key[j]) - 'A' > 90)
        {
          printf("%c", text[i] - 26 + toupper(key[j]) - 'A');
        }
        else
        {
          printf("%c", text[i] + toupper(key[j]) - 'A');
        }
      }
      else if(islower(text[i]))
      {
        if(text[i] + tolower(key[j]) - 'a' > 122)
        {
          printf("%c", text[i] - 26 + tolower(key[j]) - 'a');
        }
        else
        {
          printf("%c", text[i] + tolower(key[j]) - 'a');
        }
      }
    }
    else
    {
      k--;
      printf("%c", text[i]);
    }
  }
  printf("\n");
}

int usage()
{
  printf("\nPlease input valid alphabets.\nExample: ./vigenere banana\n\n");
  exit(1);
}