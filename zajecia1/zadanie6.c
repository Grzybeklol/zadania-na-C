#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define iloscrund 10
int main()
{
    
    int rundy[iloscrund][3];
    char wyniki[iloscrund];
    for(int i=0;i<iloscrund;i++){
        printf("Wybierz ruch: 0 - kamien 1 - papier 2 - nozyce | 3 - wyniki\n");
        int ruch;
        int randomruch = rand() % 3;
        scanf("%d", &ruch);
        if (ruch == 3) {
            for (int j = 0; j < i; j++) {
                printf("runda: %d \n", j);
                printf("twuj ruch: %d ruch komupera: %d wynik: %c \n", rundy[j][0], rundy[j][1], wyniki[j]);
            }
            i--;
            continue;
        }

        if (ruch > 3) {
            printf("bledny ruch koniec zabawy");
            break;
        }
        rundy[i][0] = ruch;
        rundy[i][1] = randomruch;
        
        switch (ruch)
        {
        case 0:
            if(randomruch==0){
                wyniki[i] = 'r';
                printf("kamien vs kamien | remis \n");
            }else if(randomruch==1){
                wyniki[i] = 'l';
                printf("kamien vs papier | przegrana \n");
            }else {
                wyniki[i] = 'w';
                printf("kamien vs nozyce | wygrana \n");
            }
            break;
        
        case 1:
            if(randomruch==0){
                wyniki[i] = 'w';
                printf("paipier vs kamien | wygrana \n");
            }else if(randomruch==1){
                wyniki[i] = 'r';
                printf("paipier vs papier | remis \n");
            }else {
                wyniki[i] = 'l';
                printf("paipier vs nozyce | przegrana \n");
            }
            break;
        
        case 2:
            if(randomruch==0){
                wyniki[i] = 'l';
                printf("nozyce vs kamien | przegrana \n");
            }else if(randomruch==1){
                wyniki[i] = 'w';
                printf("nozyce vs papier | wygrana \n");
            }else {
                wyniki[i] = 'r';
                printf("nozyce vs nozyce | remis \n");
            }
            break;
        }
    }
}
