#include <stdio.h>

int main()
{
    int j = 10;
    int suma =0;
    for (int i = 0;i <j;i++) {
        if (i % 3 == 0) {
            suma += i;
        }
        if (i % 5 == 0) {
            suma += i;
        }
    }
    printf("suma: %d,", suma);
    return 0;
}
