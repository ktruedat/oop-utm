#include <iostream>

struct Vector {
    int* elements;
    int numarElemente; 

    Vector(int numarElemente) {
        this->numarElemente = numarElemente;
        elements = new int[numarElemente];
        for (int i = 0; i < numarElemente; i++) {
            elements[i] = 0; 
        }
    }

    void eliminaVector() {
        delete[] elements;
        numarElemente = 0;
    }

    void seteazaDimensiune(int nouaDimensiune) {
        if (nouaDimensiune != numarElemente) {
            delete[] elements;
            elements = new int[nouaDimensiune];
            numarElemente = nouaDimensiune;
        }
    }

    int& operator[](int index) {
        if (index < 0 || index >= numarElemente) {
            throw std::out_of_range("Indexul este în afara limitelor");
        }
        return elements[index];
    }

    double mediaElementelorPozitive() const {
        int suma = 0;
        int numarElementePozitive = 0;
        for (int i = 0; i < numarElemente; i++) {
            if (elements[i] > 0) {
                suma += elements[i];
                numarElementePozitive++;
            }
        }
        if (numarElementePozitive == 0) {
            return 0.0; 
        }
        return static_cast<double>(suma) / numarElementePozitive;
    }
};

int main() {
    Vector vector1(5); 
    Vector vector2(3); 

    for (int i = 0; i < 5; i++) {
        vector1[i] = i + 1;
    }

    for (int i = 0; i < 3; i++) {
        vector2[i] = i * 2;
    }

    double mediaVector1 = vector1.mediaElementelorPozitive();
    double mediaVector2 = vector2.mediaElementelorPozitive();

    std::cout << "Media elementelor pozitive ale vectorului 1: " << mediaVector1 << std::endl;
    std::cout << "Media elementelor pozitive ale vectorului 2: " << mediaVector2 << std::endl;

    vector1.eliminaVector();
    vector2.eliminaVector();

    return 0;
}
