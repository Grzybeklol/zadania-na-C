#include <stdio.h>

int dodaj(int a, int b){
    return a+b;
}

int odejmij(int a, int b){
    return a-b;
}

int pomnoz(int a, int b){
    return a*b;
}

int main()
{   
    int a = 8;
    int b = 4;
    
    int (*operation)(int, int);

    printf("Jakie działanie chcesz wykonać?\n");
    printf("1. Dodawanie\n");
    printf("2. Odejmowanie\n");
    printf("3. Mnożenie\n");
    int wybor;
    scanf("%d", &wybor);

    switch (wybor)
    {
    case 1:
        operation = dodaj; 
        break;
    case 2:
        operation = odejmij;
        break;
    case 3:
        operation = pomnoz;
        break;
    
    default:
        break;
    }

    printf("Wynik działania to: %d\n", operation(a, b));

    return 0;
}