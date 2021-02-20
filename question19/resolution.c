#include <gc/gc.h>
#include <assert.h>
#include <stdio.h>

// https://www.hboehm.info/gc/simple_example.html
// compile with gcc -o result resolution.c -lgc

int main()
{
  int i;

  GC_INIT(); /* Optional on Linux/X86; see below.  */
  for (i = 0; i < 10000000; ++i)
  {
    int **p = (int **)GC_MALLOC(sizeof(int *));
    int *q = (int *)GC_MALLOC_ATOMIC(sizeof(int));
    assert(*p == 0);
    *p = (int *)GC_REALLOC(q, 2 * sizeof(int));
    if (i % 100000 == 0)
      printf("Heap size = %d\n", GC_get_heap_size());
  }
  return 0;
}
