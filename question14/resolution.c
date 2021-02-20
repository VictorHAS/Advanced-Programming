#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) // Provides 2 pointers
{
  return (*(float *)a - *(float *)b); // compares two elements.
}

int main()
{

  int n;
  float *vector;

  printf("Enter the number of values to be sorted : \n");
  scanf("%d", &n);

  vector = malloc(n * sizeof(float)); // Dynamic allocation

  printf("Values to be sorted: \n");

  for (int i = 0; i < n; i++)
  {
    scanf("%f", &vector[i]); // Input values
  }

  qsort(vector, n, sizeof(float), cmpfunc); // Call qsort function
  for (int k = 0; k < n; k++)
    printf("%f ", vector[k]);

  free(vector); // deallocates the memory previously allocated by a call to malloc

  return 0;
}
