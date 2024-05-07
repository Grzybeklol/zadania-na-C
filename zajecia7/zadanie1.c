#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool compareDigitInString(char** linePtr, const char* strToCheck) {
    for (int i = 0; strToCheck[i]; i++, (*linePtr)++) {
        if (**linePtr != strToCheck[i]) {
            (*linePtr) -= i;
            return false;
        }
    }
    return true;
}

int findDigits(char** linePtr) {
    char* start = *linePtr;
    switch (*((*linePtr)++)) {
        case 'o': return compareDigitInString(linePtr, "ne") ? 1 : -1;
        case 't': return compareDigitInString(linePtr, "wo") ? 2 : compareDigitInString(linePtr, "hree") ? 3 : -1;
        case 'f': return compareDigitInString(linePtr, "our") ? 4 : compareDigitInString(linePtr, "ive") ? 5 : -1;
        case 's': return compareDigitInString(linePtr, "ix") ? 6 : compareDigitInString(linePtr, "even") ? 7 : -1;
        case 'e': return compareDigitInString(linePtr, "ight") ? 8 : -1;
        case 'n': return compareDigitInString(linePtr, "ine") ? 9 : -1;
        case 'z': return compareDigitInString(linePtr, "ero") ? 0 : -1;
        default: (*linePtr)--; return -1;
    }
}

int getFirstAndLastDigit(char* line) {
    int firstDigit = -1, secondDigit = -1;
    while (*line) {
        if (*line >= '0' && *line <= '9') {
            secondDigit = *line - '0';
            if (firstDigit == -1) firstDigit = secondDigit;
        } else {
            int digit = findDigits(&line);
            if (digit != -1) {
                secondDigit = digit;
                if (firstDigit == -1) firstDigit = secondDigit;
            }
        }
        line++;
    }
    return firstDigit * 10 + secondDigit;
}

int main(){
    FILE *file = fopen("zajecia7/input_1.txt", "r");
    if (!file) return 1;

    char line[200];
    int result = 0;
    while (fgets(line, sizeof(line), file)) {   
        result += getFirstAndLastDigit(line);
    }
    fclose(file);
    printf("WYNIK KONCOWY \t%d\n", result);
    return 0;
}