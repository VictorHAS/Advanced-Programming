#include <stdio.h>

int main()
{
    int i=2, j=4, *p, *q;

    p = i;  //  ‘int *’ from ‘int’ makes pointer from integer without a cast
    q = &j; // Okay
    p = &*&i; // Okay
    //i = (*&)j; // error IDE waiting for expression
    i = *&j; // Okay
    i = *&*&j; // Okay
    q = *p; // ‘int *’ from ‘int’ makes pointer from integer without a cast
    // i = (*p)++ + *q; //  Error segmentation fault


    return 0;
}
