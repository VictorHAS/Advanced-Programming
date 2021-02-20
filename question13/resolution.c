#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, aux;
  float *vector;

  printf("\nSize of vector: ");
  scanf("%d", &n);

  vector = malloc(n * sizeof(float)); // Dynamic allocation

  printf("\nValues: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &vector[i]);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (vector[i] > vector[j])
      {
        aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
      }
    }
  }

  printf("\nVector sorted in ascending order: \n");
  for (int i = 0; i < n; i++)
  {
    printf("%f", vector[i]);
    printf(" ");
  }

  free(vector);

  return 0;
}