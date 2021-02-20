#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float cmpfunc(float a, float b) // compares two values to find out if it's lower or higher
{
  if (a >= b)
  {
    return 1;
  }
  return -1;
}

float selectionSortVector(float v[], int n, float (*f)(float,  float))
{
  int min;
  float aux;

  for (int i = 0; i < n - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (cmpfunc(v[j], v[min]) < 0)
        min = j;
    }
    aux = v[i];
    v[i] = v[min];
    v[min] = aux;
  }
}

int main()
{
  int n;
  float *vector;

  printf("Enter the number of values to be sorted: \n");
  scanf("%d", &n);

  vector = malloc(n * sizeof(float)); // Dynamic allocation

  printf("Values to be sorted: \n");

  for (int i = 0; i < n; i++)
  {
    scanf("%f", &vector[i]); // Input values
  }

  selectionSortVector(vector, n, cmpfunc);

  printf("Vector ordered:  \n");

  for (int j = 0; j < n; j++)
  {
    printf(" %f", vector[j]);
  }
  printf("\n");

  free(vector); // deallocates the memory previously allocated by a call to malloc

  return 0;
}
