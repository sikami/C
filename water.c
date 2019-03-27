#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int bottle, minute;
  printf("Minutes: ");
  minute = GetInt();
  bottle = (minute * 1.5 * 128) / 16;
  printf("Bottles: %i\n", bottle);
}