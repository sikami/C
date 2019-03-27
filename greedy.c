#include <cs50.h>
#include <stdio.h>
#include <math.h> 

int main(void)
{
  float change;
  int coins = 0;
       
  do
  {
    printf("Hi, how much change is owed? \n");
    change = get_float();
  }
  while (change < 0);
  
  int a = round(change * 100);    
      
  while (a > 0)
  {   
    if (a >= 25)
    {
      int b;
      b = (a/25);
      coins += b;
      a = (a - (b*25));                                    
    }
    if (a >= 10) 
    {
      int b;
      b = a/10;
      coins += b;
      a = (a - (b*10));                    
    }    
    if (a >= 5)
    {
      int b;
      b = a/5;
      coins +=b;
      a = (a - (b*5));                    
    }
    if (a >= 1)
    {
      int b;
      b = a/1;
      coins += b;
      a = (a - (b*1));
    }
    printf("%d\n", coins);      
  }            
}