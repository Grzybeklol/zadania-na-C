#include <stdio.h>


int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int silnia;
    int sum;
    for (int i = 0;i < 10;i++) {
        if (i == 0) {
            sum = 1;
            silnia = 1;
            continue;
        }
        silnia = sum * array[i];
        sum = silnia;

    }
    printf("silnia: %d", silnia);
    return 0;
}
