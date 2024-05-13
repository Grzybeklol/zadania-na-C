#include <iostream>
#include <fstream>
#include <string>

class DigitFinder {
public:
    bool compareDigitInString(const char*& linePtr, const std::string& strToCheck) {
        for (size_t i = 0; i < strToCheck.length(); i++, linePtr++) {
            if (*linePtr != strToCheck[i]) {
                linePtr -= i;
                return false;
            }
        }
        return true;
    }

    int findDigits(const char*& linePtr) {
        const char* start = linePtr;
        switch (*(linePtr++)) {
            case 'o': return compareDigitInString(linePtr, "ne") ? 1 : -1;
            case 't': return compareDigitInString(linePtr, "wo") ? 2 : compareDigitInString(linePtr, "hree") ? 3 : -1;
            case 'f': return compareDigitInString(linePtr, "our") ? 4 : compareDigitInString(linePtr, "ive") ? 5 : -1;
            case 's': return compareDigitInString(linePtr, "ix") ? 6 : compareDigitInString(linePtr, "even") ? 7 : -1;
            case 'e': return compareDigitInString(linePtr, "ight") ? 8 : -1;
            case 'n': return compareDigitInString(linePtr, "ine") ? 9 : -1;
            case 'z': return compareDigitInString(linePtr, "ero") ? 0 : -1;
            default: linePtr--; return -1;
        }
    }

    int getFirstAndLastDigit(const std::string& line) {
        int firstDigit = -1, secondDigit = -1;
        const char* ptr = line.c_str();
        while (*ptr) {
            if (*ptr >= '0' && *ptr <= '9') {
                secondDigit = *ptr - '0';
                if (firstDigit == -1) firstDigit = secondDigit;
            } else {
                int digit = findDigits(ptr);
                if (digit != -1) {
                    secondDigit = digit;
                    if (firstDigit == -1) firstDigit = secondDigit;
                }
            }
            ptr++;
        }
        return firstDigit * 10 + secondDigit;
    }
};

int main() {
    std::ifstream file("zajecia7/input_1.txt");
    if (!file) return 1;

    std::string line;
    int result = 0;
    DigitFinder digitFinder;
    while (std::getline(file, line)) {
        result += digitFinder.getFirstAndLastDigit(line);
    }
    file.close();
    std::cout << "WYNIK KONCOWY \t" << result << std::endl;
    return 0;
}