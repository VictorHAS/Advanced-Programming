#include "gc.h"
#include <gc/gc.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void normal_malloc()
{
  int *vector;

  vector = malloc(100 * sizeof(int));

  for (int i = 0; i < 100; i++)
  {
    vector[i] = rand() % 100;
  }

  free(vector);
}

void libgc_Malloc()
{
  int *vector;

  vector = GC_malloc(100 * sizeof(int));

  for (int i = 0; i < 100; i++)
  {
    vector[i] = rand() % 100;
  }
}

int main()
{
  // It is usually best not to mix garbage-collected allocation with the system malloc-free. If you do, you need to be careful not to store pointers to the garbage-collected heap in memory allocated with the system malloc.
  clock_t time1;
  clock_t time2;

  time1 = clock();
  normal_malloc();
  time1 = clock() - time1;
  printf("Execution time normal malloc: %lf", ((double)time1) / ((CLOCKS_PER_SEC / 1000)));
  printf("ms.");

  time2 = clock(); // Variável para armazenar tempo;
  libgc_Malloc();
  time2 = clock() - time2;
  printf("\nExecution time GC_malloc from libgc: %lf", ((double)time2) / ((CLOCKS_PER_SEC / 1000)));
  printf("ms.\n");

  return 0;
}
