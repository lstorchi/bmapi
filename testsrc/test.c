#include <stdio.h>

int main (int argc, char ** argv)
{
  unsigned int number = 3;
  int i, bit;

  for (i=0; i<=31; ++i)
  {
    bit = (number >> i) & 1U;
    printf("%u %d\n", bit, i);
  }

  /*
  for (i=0; i<=31; ++i)
  {
    number |= 1U << i;
    printf("%u %d\n", number, i);
  }
  */

  return 0;
}
