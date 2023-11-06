#include <iostream>
#include <stdexcept>

class Matrix {
private:
    long* data;
    int rows;
    int cols;
    int errorCode;

public:
    Matrix() : data(nullptr), rows(0), cols(0), errorCode(0) {}

    Matrix(int n) : rows(n), cols(n), errorCode(0) {
        if (n <= 0) {
            errorCode = 1; 
            return;
        }
        data = new long[n * n]();
    }

    Matrix(int x, int y) : rows(x), cols(y), errorCode(0) {
        if (x <= 0 || y <= 0) {
            errorCode = 1;
            return;
        }
        data = new long[x * y]();
    }

    ~Matrix() {
         delete[] data; 
        //  Matricea data a fost alocată ca un singur bloc de memorie, nu ca un vector de pointeri la alte matrice.
    }

    void setElement(int row, int col, long value) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            errorCode = 2;
            return;
        }
        data[row * cols + col] = value;
    }

    long getElement(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            // errorCode = 2;
            return 0;
        }
        return data[row * cols + col];
    }

    int getCols(){
        return cols;
    }

     int getRows(){
        return rows;
    }

    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            // errorCode = 3;
            return Matrix();
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, getElement(i, j) + other.getElement(i, j));
            }
        }
        return result;
    }

    Matrix subtract(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            // errorCode = 3;
            return Matrix();
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, getElement(i, j) - other.getElement(i, j));
            }
        }
        return result;
    }

    Matrix multiply(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, getElement(i, j) * other.getElement(i, j));
            }
        }

        return result;
    }


    Matrix multiplyByNumber(long num) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, getElement(i, j) * num);
            }
        }
        return result;
    }

    int getErrorCode() const {
        return errorCode;
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), errorCode(other.errorCode) {
        data = new long[rows * cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                setElement(i, j, other.getElement(i, j));
            }
        }
    }

    Matrix& operator=(const Matrix& other) {
    if (this != &other) {
        delete[] data;
        rows = other.rows;
        cols = other.cols;
        errorCode = other.errorCode;
        data = new long[rows * cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                setElement(i, j, other.getElement(i, j));
            }
        }
    }
    return *this;
}
};

int main() {
    Matrix A(2, 3);
    A.setElement(0, 0, 1);
    A.setElement(0, 1, 2);
    A.setElement(0, 2, 3);
    A.setElement(1, 0, 4);
    A.setElement(1, 1, 5);
    A.setElement(1, 2, 6);

    Matrix B(2, 3);
    B.setElement(0, 0, 4);
    B.setElement(0, 1, 5);
    B.setElement(0, 2, 6);
    B.setElement(1, 0, 7);
    B.setElement(1, 1, 8);
    B.setElement(1, 2, 9);

    std::cout <<"Adunarea\n";


    Matrix C = A.add(B);

    if (C.getErrorCode() == 0) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << C.getElement(i, j) << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Error: ";
        if (C.getErrorCode() == 1) {
            std::cout << "Invalid matrix size or index.";
        } else if (C.getErrorCode() == 3) {
            std::cout << "Matrix size mismatch.";
        }
    }

    std::cout <<"Diferenta\n";


    Matrix D = B.subtract(A);
    if (D.getErrorCode() == 0) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << D.getElement(i, j) << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Error: ";
        if (D.getErrorCode() == 1) {
            std::cout << "Invalid matrix size or index.";
        } else if (D.getErrorCode() == 3) {
            std::cout << "Matrix size mismatch.";
        }
    }

    std::cout <<"Inmultirea cu un nr\n";


    Matrix E = A.multiplyByNumber(3);
     if (E.getErrorCode() == 0) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << E.getElement(i, j) << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Error: ";
        if (E.getErrorCode() == 1) {
            std::cout << "Invalid matrix size or index.";
        } else if (E.getErrorCode() == 3) {
            std::cout << "Matrix size mismatch.";
        }
    }

    std::cout <<"Inmultirea a doua matrici\n";

    Matrix F = A.multiply(B);

    if (F.getErrorCode() == 0) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << F.getElement(i, j) << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Error: ";
        if (F.getErrorCode() == 1) {
            std::cout << "Invalid matrix size or index.";
        } else if (F.getErrorCode() == 3) {
            std::cout << "Matrix size mismatch.";
        }
    }

    return 0;
}
