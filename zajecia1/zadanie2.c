#include <stdio.h>

    int main() {
        int grades[2][5] = { {0,2,3,4,5},{2,3,4,5,6} };
        float sumamat = 0.;
        float sumafiz = 0.;
        for (int i = 0;i < 5;i++) {
            sumamat += grades[0][i];
            sumafiz += grades[1][i];
        }
        float sredniamat = sumamat / 5;
        float sredniafiz = sumafiz / 5;
        printf("Srednia z mat: %f  a srednia z fiz =%f", sredniamat, sredniafiz);
        return 0;
    }




