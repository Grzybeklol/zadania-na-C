#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x,y;

    printf("Podaj pierwszy rozmiar: ");
    scanf("%d", &x);

    printf("Podaj drugi rozmiar: ");
    scanf("%d", &y);

    int **macierz = (int **) malloc(x * sizeof(int *));

    for(int i = 0; i < x; i++){
        macierz[i] = (int *) malloc(y * sizeof(int *));
        for(int j = 0; j < y; j++){
            macierz[i][j] = rand() % (99);
        }
    }


    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
        free(macierz[i]);
    }

    free(macierz);
    return 0; 
}