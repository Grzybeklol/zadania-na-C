#include <stdio.h> 

void zrubcos(float *f){
    *f *= 2;
}

int main()
{   
    float f = 21.37;
    zrubcos(&f);
    printf("%f",f);
    return 0;
}

