#include <iostream>
#include <stdexcept>

class Matrix {
private:
    long* data; // Pointer către matrice
    int numRows; // Numărul de rânduri
    int numCols; // Numărul de coloane
    int errorCode; // Codul de eroare (0 = fără eroare, 1 = eroare de dimensiune, 2 = eroare de memorie)

public:
    // Constructor implicit (fără parametri)
    Matrix() : data(nullptr), numRows(0), numCols(0), errorCode(0) {}

    // Constructor pentru o matrice pătrată de dimensiune n x n
    Matrix(int n) : numRows(n), numCols(n), errorCode(0) {
        if (n <= 0) {
            errorCode = 1; // Eroare de dimensiune
            return;
        }
        data = new long[n * n];
    }

    // Constructor pentru o matrice dreptunghiulară de dimensiune numRows x numCols
    Matrix(int numRows, int numCols) : numRows(numRows), numCols(numCols), errorCode(0) {
        if (numRows <= 0 || numCols <= 0) {
            errorCode = 1; // Eroare de dimensiune
            return;
        }
        data = new long[numRows * numCols];
    }

    // Funcție pentru a obține valoarea elementului (i, j)
    long getElement(int i, int j) {
        if (i < 0 || i >= numRows || j < 0 || j >= numCols) {
            errorCode = 1; // Eroare de dimensiune
            throw std::out_of_range("Indici incorecți");
        }
        return data[i * numCols + j];
    }

    // Funcție pentru a seta valoarea elementului (i, j)
    void setElement(int i, int j, long value) {
        if (i < 0 || i >= numRows || j < 0 || j >= numCols) {
            errorCode = 1; // Eroare de dimensiune
            throw std::out_of_range("Indici incorecți");
        }
        data[i * numCols + j] = value;
    }

    // Funcție pentru a verifica dacă există erori
    bool hasError() {
        return errorCode != 0;
    }

    // Funcție pentru a afișa matricea
    void printMatrix() {
        if (hasError()) {
            std::cout << "Eroare: ";
            if (errorCode == 1) {
                std::cout << "Eroare de dimensiune";
            } else if (errorCode == 2) {
                std::cout << "Eroare de memorie";
            }
            std::cout << std::endl;
            return;
        }

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                std::cout << data[i * numCols + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Destructor pentru eliberarea memoriei
    ~Matrix() {
        delete[] data;
    }
};

int main() {
    // Exemplu de utilizare a clasei Matrix
    Matrix squareMatrix(3); // Matrice pătrată de 3x3
    squareMatrix.setElement(0, 0, 1);
    squareMatrix.setElement(1, 1, 2);
    squareMatrix.setElement(2, 2, 3);
    squareMatrix.printMatrix();

    Matrix rectangularMatrix(2, 4); // Matrice dreptunghiulară de 2x4
    rectangularMatrix.setElement(0, 0, 4);
    rectangularMatrix.setElement(1, 2, 7);
    rectangularMatrix.printMatrix();

    return 0;
}
