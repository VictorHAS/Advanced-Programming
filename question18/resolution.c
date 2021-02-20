#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mult(int **A, int **B, int **C, int nlA, int ncA, int ncB)
{
  int aux = 0;

  for (int i = 0; i < nlA; i++)
  {
    for (int j = 0; j < ncB; j++)
    {
      C[i][j] = 0;

      for (int k = 0; k < ncA; k++)
      {
        aux += (A[i][k] * B[k][j]);
      }

      C[i][j] = aux;
      aux = 0;
    }
  }
}

int main()
{

  int **A, **B, **C, nlA, ncA, ncB;

  printf("Number of lines A: \n");
  scanf("%d", &nlA);
  printf("Number of columns A: \n");
  scanf("%d", &ncA);
  printf("Number of columns B: \n");
  scanf("%d", &ncB);

  // Aloca os blocos auxiliares;

  A = malloc(nlA * sizeof(int *));
  B = malloc(ncA * sizeof(int *));
  C = malloc(nlA * sizeof(int *));

  // Aloca linhas;

  A[0] = malloc(nlA * ncA * sizeof(int));
  B[0] = malloc(ncA * ncB * sizeof(int));
  C[0] = malloc(nlA * ncB * sizeof(int));

  for (int i = 1; i < nlA; i++)
  {
    A[i] = A[i - 1] + ncA;
    C[i] = C[i - 1] + ncB;
  }

  for (int j = 1; j < ncA; j++)
  {
    B[j] = B[j - 1] + ncB;
  }

  printf("\nA elements: \n");

  for (int x = 0; x < nlA; x++)
  {
    for (int y = 0; y < ncA; y++)
    {
      scanf("%d", &A[x][y]);
    }
  }

  printf("\nB elements: \n");

  for (int x = 0; x < ncA; x++)
  {
    for (int y = 0; y < ncB; y++)
    {
      scanf("%d", &B[x][y]);
    }
  }

  mult(A, B, C, nlA, ncA, ncB);

  printf("\nMatriz A: \n");
  for (int x = 0; x < nlA; x++)
  {
    for (int y = 0; y < ncA; y++)
    {
      printf("%d ", A[x][y]);
    }
    printf("\n");
  }

  printf("\nMatriz B: \n");
  for (int x = 0; x < ncA; x++)
  {
    for (int y = 0; y < ncB; y++)
    {
      printf("%d ", B[x][y]);
    }
    printf("\n");
  }

  printf("\nMatriz C: \n");
  for (int x = 0; x < nlA; x++)
  {
    for (int y = 0; y < ncB; y++)
    {
      printf("%d ", C[x][y]);
    }
    printf("\n");
  }

  free(A[0]);
  free(B[0]);
  free(C[0]);
  free(A);
  free(B);
  free(C);

  return 0;
}
