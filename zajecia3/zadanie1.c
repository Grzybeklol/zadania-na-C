#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    int wynik =1;
    for(int i =1;i<=n;i++){
        wynik *= i;
    }
    return wynik;
}

int obliczliczbe(int n, int k){
    return (factorial(n) / (factorial(k) * factorial(n-k)));
}

int main(){

    int n;
    printf("Podaj wysokosc: ");
    scanf("%d", &n);


    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d", obliczliczbe(i,j));
        }
        printf("\n");
    }

    return 0;
}