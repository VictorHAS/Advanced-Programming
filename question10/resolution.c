#include <stdio.h>

int main()
{

    char x1[4];
    short int x2[4];
    float x3[4];
    double x4[4];


    printf("\nchar: \n"); //1 byte;
    printf("%p", x1 );
    printf("\n%p", x1 + 1);
    printf("\n%p", x1 + 2);
    printf("\n%p", x1 + 3);

    printf("\nshort int: \n"); //2 bytes;
    printf("%p", x2 );
    printf("\n%p", x2 + 1);
    printf("\n%p", x2 + 2);
    printf("\n%p", x2 + 3);

    printf("\nfloat: \n"); //4 bytes;
    printf("%p", x3 );
    printf("\n%p", x3 + 1);
    printf("\n%p", x3 + 2);
    printf("\n%p", x3 + 3);

    printf("\ndouble: \n"); //8 bytes;
    printf("%p", x4);
    printf("\n%p", x4 + 1);
    printf("\n%p", x4 + 2);
    printf("\n%p", x4 + 3);

    printf("\n");
    printf("\nTamanho do char: %lu", sizeof(char));
    printf("\nTamanho do int: %lu", sizeof(short int));
    printf("\nTamanho do float: %lu", sizeof(float));
    printf("\nTamanho do double: %lu", sizeof(double));
    printf("\n");

    return 0;
}
