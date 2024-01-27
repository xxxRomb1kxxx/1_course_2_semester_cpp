#include <random>
#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        data = new int* [rows]; // доп память
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = rand();
            }
        }
    }
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) { // кон_коп
        data = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& other) { // op_copy
        if (this != &other) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;

            rows = other.rows;
            cols = other.cols;
            data = new int* [rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new int[cols];
            }

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main() {

    Matrix matrix1(5, 5);
    matrix1.print();
    std::cout << "/////////" << std::endl;
    Matrix matrix2 = matrix1;
    matrix2.print();
    std::cout << "/////////" << std::endl;
    Matrix matrix3(5, 5);
    matrix3 = matrix1;
    matrix3.print();

    return 0;
}
