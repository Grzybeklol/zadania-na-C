#include <stdio.h>
#include <stdlib.h>

#define len 3

struct Student{
    char imie[15];
    float ocena;
};

int main()
{   
    
    struct Student students[len] = {
        {"Jan", 4.5},
        {"Pawel", 3.7},
        {"Juzef", 3.9}
    };

    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (students[j].ocena < students[j + 1].ocena) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < len; ++i) {
        printf("Student %d: Imie: %s, Ocena: %f\n", i + 1, students[i].imie, students[i].ocena);
    }

    return 0;
}
