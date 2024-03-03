#include <stdio.h>
#include <cstring>

#define len 5

struct Contact {
    char imie[15];
    char nazwisko[20];
    char number[9];
};

void dodajkontakt(struct Contact *con, int *koniec) {
    struct Contact c1;
    printf("Podaj dane:\n");
    printf("imie:");
    scanf("%s", c1.imie);
    printf("nazwisko:");
    scanf("%s", c1.nazwisko);
    printf("numer:");
    scanf("%s", c1.number);
    con[*koniec] = c1; 
    (*koniec)++;
}

void Wyszukiwania(struct Contact *con, int *koniec) {
    printf("Podaj nazwisko: ");
    char nazwisko[20];
    scanf("%s", nazwisko);
    for(int i = 0; i < *koniec; i++) {
        if (strcmp(con[i].nazwisko, nazwisko) == 0) {
            printf("Imie: %s , Nazwisko: %s , Number: %s\n", con[i].imie, con[i].nazwisko, con[i].number);
        } 
    }
}

void Usuwanie(struct Contact *con, int *koniec) {
    printf("Podaj nazwisko: ");
    char nazwisko[20];
    scanf("%s", nazwisko);
    for(int i = 0; i < *koniec; i++) {
        if (strcmp(con[i].nazwisko, nazwisko) == 0) {
            con[i].imie[0] = '\0';
            con[i].nazwisko[0] = '\0';
            con[i].number[0] = '\0';
        } 
    }
}

void Wypisz(struct Contact *con, int *koniec) {
    for(int i = 0; i < *koniec; i++) {
        printf("Imie: %s , Nazwisko: %s , Number: %s\n", con[i].imie, con[i].nazwisko, con[i].number);
    }
}

int main() {
    
    struct Contact tablica[len] = {
        {"Jan", "Pawel", "21374206"},
        {"Adam", "Malusz", "66674206"},
        {"Rychu", "Peja", "33374206"},
    };
    int pointerkonca = 3;

    while(1) {
        int decyzja;
        printf("Co chcesz zrobic: 1-Dodaj\n2-Wyszukaj\n3-Usun\n4-Wypisz\n");
        scanf("%d", &decyzja);
    
        switch (decyzja) {
            case 1:
                dodajkontakt(tablica, &pointerkonca);
                break;
            case 2:
                Wyszukiwania(tablica, &pointerkonca);
                break;
            case 3:
                Usuwanie(tablica, &pointerkonca);
                break;
            case 4:
                Wypisz(tablica, &pointerkonca);
                break;
            default:
                printf("Niepoprawna opcja\n");
                break;
        }
    }
    return 0;
}
