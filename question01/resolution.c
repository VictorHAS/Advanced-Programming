#include <stdio.h>

int main()
{
  int i = 3, j = 5;
  int *p, *q;
  p = &i;
  q = &j;
  printf("%d\n", p == &i); // 1
  printf("%d\n", *p - *q); // -2
  printf("%d\n", **&p); // 3
  printf("%d\n", 3 - *p / (*q) + 7); // 10

  return 0;
}