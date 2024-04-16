#include <stdio.h>



int main()
{   
    int tablica[10] = {1,2,3,4,5,6,7,8,9,10};
    
    int *wsk = &tablica[0];

    for(int j=0;j<10;j++){
        printf("Element %d ma wartość %d\n", j, *wsk);
        wsk ++;
    }

    return 0;
}