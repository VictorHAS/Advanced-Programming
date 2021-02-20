#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float cmpfunc(float a, float b) // compares two values to find out if it's lower or higher
{
  if (a >= b)
    return 1;
  if (a < b)
    return -1;
}

int compare(const void *a, const void *b)
{
  return (*(float *)a - *(float *)b);
}

float selectionSortVector(float v[], int n, float (*func)(float, float))
{
  int min;
  float aux;

  for (int i = 0; i < n - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (func(v[j], v[min]) < 0)
        min = j;
    }
    aux = v[i];
    v[i] = v[min];
    v[min] = aux;
  }
}

int main()
{
  clock_t t_CustomSortVector, t_qsort;
  int n;
  float *vector1, *vector2;

  printf("Enter the number of values to be sorted: \n");
  scanf("%d", &n);

  vector1 = malloc(n * sizeof(float)); // Dynamic allocation
  vector2 = malloc(n * sizeof(float)); // Dynamic allocation

  printf("Values to be sorted: \n");

  for (int i = 0; i < n; i++)
  {
    scanf("%f", &vector1[i]); // Input values
  }
  for (int i = 0; i < n; i++)
  {
    vector2[i] = vector1[i];
  }

  t_CustomSortVector = clock(); //Store time before call function
  selectionSortVector(vector1, n, cmpfunc);
  t_CustomSortVector = clock() - t_CustomSortVector; // final time - initial time

  t_qsort = clock();
  qsort(vector2, n, sizeof(float), compare);
  t_qsort = clock() - t_qsort;

  printf("\nExecution time customSortVector: %lf", ((double)(t_CustomSortVector) / (CLOCKS_PER_SEC / 1000)));
  printf(" ms. \n \n");
  printf("\nExecution time qsort: %lf", ((double)(t_qsort) / (CLOCKS_PER_SEC / 1000)));
  printf(" ms. \n \n");

  for (int k = 0; k < n; k++)
    printf("%f ", vector2[k]);

  free(vector2); // deallocates the memory previously allocated by a call to malloc
  free(vector1); // deallocates the memory previously allocated by a call to malloc

  return 0;
}
