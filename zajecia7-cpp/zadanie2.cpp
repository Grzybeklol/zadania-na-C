#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

const int czerwone = 12;
const int zielone = 13;
const int niebieskie = 14;

class LineProcessor {
public:
    int ispossible(const std::string& line, int& moc) {
        int max[3] = {1, 1, 1}; // czerwone, zielone, niebieskie
        bool mozna = true;
        size_t index = 7;
        while (index < line.size()) {
            if (isdigit(line[index])) {
                int liczba;
                if (isdigit(line[index + 1])) {
                    liczba = (line[index] - '0') * 10 + (line[index + 1] - '0');
                    index++;
                } else {
                    liczba = line[index] - '0';
                }

                index += 2;
                switch (line[index]) {
                    case 'r':
                        if (liczba > max[0]) max[0] = liczba;
                        if (liczba > czerwone) mozna = false;
                        break;
                    case 'g':
                        if (liczba > max[1]) max[1] = liczba;
                        if (liczba > zielone) mozna = false;
                        break;
                    case 'b':
                        if (liczba > max[2]) max[2] = liczba;
                        if (liczba > niebieskie) mozna = false;
                        break;
                    default:
                        std::cerr << "error\n";
                }
            } else {
                index++;
            }
        }
        moc = max[0] * max[1] * max[2];
        return mozna ? 1 : 0;
    }
};

int main() {
    std::ifstream file("zajecia7/input_2.txt");
    if (!file) return 1;

    std::string line;
    int current = 0;
    int sume = 0;
    int summoc = 0;
    int moc = 0;
    LineProcessor processor;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        current++;
        sume += current * processor.ispossible(line, moc);
        summoc += moc;
        std::cout << current << "," << moc << std::endl;
        moc = 0;
    }

    file.close();

    std::cout << "WYNIK KONCOWY \t" << sume << "\nSUMA MOCY: " << summoc << std::endl;

    return 0;
}