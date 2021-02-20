#include <stdio.h>

int main()
{

  int pulo[5] = {10, 25, 35, 48, 59};
  int a, b, *c, *d;

  printf("\n%d", *(pulo + 2)); // Will return 35

  printf("\n%d", *(pulo + 4)); // Will Return 59

  printf("\n%p", (pulo + 2)); // Memory Address

  printf("\n%p", (pulo + 4)); // Memory Address
  printf("\n");
}
