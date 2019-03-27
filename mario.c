#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
  int height;
  int x, y, z;
    
  do
  {
    printf ("Height: ");
    height = get_int();
    if( height == 0)
    {
      return 0;
    }       
  }
  
  while (height < 1 || height > 23);
                
  for (y=0; y < height; y++)
  { 
    for (z = (height-1); z > y; z--)
    {
      printf(" ");
    }
    for(x = 0; x < (y+1); x++)
    {
      printf("#");
    } 
    printf("#\n"); 
  }  
}  
