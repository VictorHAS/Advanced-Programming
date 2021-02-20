#include <stdio.h>

int main()
{
    int i = 5, *p, k = 4094;
    p = &i;
    printf("%x %d %d %d %d", *p, *p + 2, **&p, 3**p, **&p + 4);
    printf("\nValue in memory 4094 hexadecimal: %x ", k); // 4094 to hexadecimal = ffe

    return 0;
}