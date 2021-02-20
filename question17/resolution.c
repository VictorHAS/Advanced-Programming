#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sum(int *a1, int *a2, int *a3, int n)
{
  for (int i = 0; i < n; i++)
  {
    a3[i] = a1[i] + a2[i];
  }
}

int main()
{
  int *a1, *a2, *a3, n;

  printf("Size of array: \n");
  scanf("%d", &n);

  a1 = malloc(n * sizeof(int));
  a2 = malloc(n * sizeof(int));
  a3 = malloc(n * sizeof(int));

  printf("Values of first array: \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a1[i]);
  }

  printf("Values of second array: \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a2[i]);
  }

  sum(a1, a2, a3, n);

  printf("Sum of arrays: ");
  for (int i = 0; i < n; i++)
  {
    printf("\n%d  ", a3[i]);
  }
  printf("\n");

  free(a1);
  free(a2);
  free(a3);

  return 0;
}