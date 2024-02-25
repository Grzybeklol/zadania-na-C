#include <iostream>
#include <stdio.h>
int main()
{
    char name[100];

    printf("Podaj imie: ");
    scanf("%s", name);

    printf("Witaj, %s!\n", name);
    
    return 0;
}
