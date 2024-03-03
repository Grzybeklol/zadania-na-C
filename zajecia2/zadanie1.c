#include <stdio.h>

int main()
{
    int h = 69;
    int * wsk = &h;

    *wsk -= 1;
 
    printf("bezposrednio: %d \npoprzez wskaznik: %d",h, *wsk);

    return 0;
}
