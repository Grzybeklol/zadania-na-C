#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define czerwone 12
#define zielone 13
#define niebieskie 14


int ispossible(char* line, int* moc) {
    int max[3] = {1, 1, 1}; // czerwone, zielone, niebieskie
    bool mozna = true;
    line = line+7;
    while(*line){
        if(isdigit(*line)){
            int liczba;
            if(isdigit(*(line+1))){
                liczba = (*line - '0')*10 + (*(line+1) - '0');
                *line++;
            }
            else{
                liczba = *line - '0';
            }

            line = line+2;
            switch(*line){
                case 'r':
                if(liczba>max[0]){
                    max[0] = liczba;
                }
                
                if(liczba > czerwone){
                    mozna = false;
                }
                    break;
                case 'g':
                if(liczba>max[1]){
                    max[1] = liczba;
                }
                if(liczba > zielone){
                    mozna = false;
                }
                    break;
                case 'b':
                if(liczba>max[2]){
                    max[2] = liczba;
                }
                if(liczba > niebieskie){
                    mozna = false;
                }
                    break;
                default:
                    printf("error\n");

            }

        }else{
            line++;
        }
        }
    printf("%d,%d,%d\n", max[0], max[1], max[2]);
    *moc = max[0] * max[1] * max[2];
    if(mozna){
        
        return 1;

    }
    else{
        return 0;
        }
}
int main() {
    FILE *file = fopen("zajecia7/input_2.txt", "r");
    if (!file) return 1;

    char line[200];
    int current = 0;
    int sume = 0;
    int summoc = 0;
    int moc = 0;
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
        current++;   
        sume += current * ispossible(line, &moc);
        summoc += moc;
        printf("%d,%d\n", current, moc);
        moc = 0;
    }    

    fclose(file);

    printf("WYNIK KONCOWY \t%d\nSUMA MOCY: %d\n" , sume, summoc);
    
    return 0;
}