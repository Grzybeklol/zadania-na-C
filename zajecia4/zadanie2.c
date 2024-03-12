#include <stdio.h>

#define len 10

int wyszukiwanie(int *pointer, int szukana, int lewa, int prawa) {
    if (prawa >= lewa) {
        int srodek = (prawa+lewa)/2;
        
        if (pointer[srodek] == szukana) {
            return srodek; 
        }
        
        if (pointer[srodek] > szukana) {
            return wyszukiwanie(pointer, szukana, lewa, srodek - 1);
        } else {
            return wyszukiwanie(pointer, szukana, srodek + 1, prawa);
        }
    }
    
    return -1; 
}

int main(){
    int tablica[len] = {0,2,4,7,9,11,15,18,19,21};

    for(int i=1;i<len;i++){
        if(tablica[i]<tablica[i-1]){
            printf("tablia nie posortowana");
            return 0;
        }
    }
    int liczba = 9;
    printf("tablica posrtowana zaczynam wyszukiwanaie indexu liczby %d \n",liczba);
    int result = wyszukiwanie(tablica, liczba, 0, len-1);
    printf("Element jest na indexie : %d", result);
    return 0;
}