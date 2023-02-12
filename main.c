#include <stdio.h>
#include <stdlib.h>
#include "ptr.h"
int main()
{
    int a=42;
    int b=43;
    printf("before inc a is %d, b is %d\n",a,b);
    #ifdef PTR
    inc (&a, &b);
    printf ("after inc a is %d\, b is %d\n", a,b);
    swap(&a, &b);
    printf("after swap a is %d\, b is %d\n", a,b);

    #else
    inc (a.b);
    printf("after inc a is %d\, b is %d\n", a,b);
    swap(a,b);
    printf("after swap a is %d\, b is %d\n", a,b);
    #endif // PTR
    printf("Reverse polish logic calculator\n");
    calc();
    return 0;
}
