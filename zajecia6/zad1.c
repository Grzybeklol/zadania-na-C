#include <stdio.h>

union typy{
    int calk;
    float zmienno;
    char znak;
};


int main()
{   
    union typy zmienna;
    zmienna.calk = 55;
    printf("%i\n", zmienna.calk);
    zmienna.zmienno = 21.37f;
    printf("%f\n", zmienna.zmienno);
    zmienna.znak = 'g';
    printf("%c\n", zmienna.calk);

    return 0;
}