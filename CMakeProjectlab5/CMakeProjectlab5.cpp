#include <iostream>
#include "CMakeProjectlab5.h"
template <typename T, int N, int M>
class Matrix {
private:
    T data[N][M];
public:
    Matrix() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = T();
            }
        }
    }
    Matrix(const Matrix& other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    Matrix& operator=(const Matrix& other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }
    friend std::istream& operator>>(std::istream& in, Matrix& matrix) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                in >> matrix.data[i][j];
            }
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                out << matrix.data[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix& operator+=(const Matrix& other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < M; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    Matrix& operator*=(const Matrix& other) {
        Matrix result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < M; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        *this = result;
        return *this;
    }
    Matrix& operator++() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j]++;
            }
        }
        return *this;
    }
    T determinant() const {
        if (N != M) {
            throw std::out_of_range("out_of_range");
        }
        else if (N == 1) {
            return data[0][0];
        }
        else if (N == M && N == 2) {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }
        else {
            return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
                data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
                data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
        }
    }
    T& operator()(int i, int j) {
        return data[i][j];
    }
    T get_element(size_t i, size_t j) const {
        if (i < N && j < M) {
            return data[i][j];
        }
        else {
            std::cerr << "Error." << std::endl;
            return T{};
        }
    }
    void set_element(size_t i, size_t j, T value) {
        if (i < N && j < M) {
            data[i][j] = value;
        }
        else {
            std::cerr << "Error" << std::endl;
        }
    }

};

int main() {

    Matrix<int, 3, 3> matrix1;
    Matrix<int, 3, 3> matrix2;
    std::cout << "matrix 1" << std::endl;
    std::cin >> matrix1;
    std::cout << "matrix 2" << std::endl;
    std::cin >> matrix2;
    Matrix<int, 3, 3> result = matrix1 + matrix2;
    std::cout << "Matrix 1 + Matrix 2:" << std::endl;
    std::cout << result << std::endl;
    result = matrix1 * matrix2;
    std::cout << "Matrix 1 * Matrix 2:" << std::endl;
    std::cout << result << std::endl;
    ++matrix1;
    std::cout << "++ Matrix 1:" << std::endl;
    std::cout << matrix1 << std::endl;
    std::cout << "Determinant of Matrix 1:" << std::endl;
    std::cout << matrix1.determinant() << std::endl;
    std::cout << "Element (1, 1) of Matrix 2:" << std::endl;
    std::cout << matrix2(1, 1) << std::endl;
    matrix2(1, 1) = 10;
    std::cout << "Modified element (1, 1) of Matrix 2:" << std::endl;
    std::cout << matrix2(1, 1) << std::endl;
    std::cout << matrix2 << std::endl;
    int element = matrix1.get_element(2, 2);
    std::cout << "element of matrix1" << std::endl;
    std::cout << element << std::endl;
    matrix1.set_element(2, 2, 1000);
    std::cout << matrix1 << std::endl;
    return 0;
}