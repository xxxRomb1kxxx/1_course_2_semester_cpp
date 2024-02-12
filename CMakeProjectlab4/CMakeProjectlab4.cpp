#include "CMakeProjectlab4.h"
#include <iostream>
class Bigint {
private:
    int rows;
    int cols;
    int** data;

public:
    Bigint(int numRows, int numCols) : rows(numRows), cols(numCols) {
        data = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = rand();
            }
        }
    }
    Bigint(const Bigint& other) : rows(other.rows), cols(other.cols) {
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
    Bigint& operator=(const Bigint& other) {
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
    ~Bigint() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
    Bigint& operator+(const Bigint& other) {
        Bigint* sum = new Bigint(other.rows, other.cols);
        for (int i = 0; i < other.cols; i++) {
            for (int j = 0; j < other.rows; j++) {
                sum->data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return *sum;
    }
    Bigint& operator+=(const Bigint& other) {

        for (int i = 0; i < other.cols; i++) {
            for (int j = 0; j < other.rows; j++) {
                data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return *this;
    }
    Bigint operator*(const Bigint& other) const {
        Bigint result(rows, cols);
        result.rows = rows;
        result.cols = other.cols;

        if (cols != other.rows) {
            std::cerr << "Error" << std::endl;
            return result;
        }
        for (int i = 0; i < result.rows; ++i) {
            for (int j = 0; j < result.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    Bigint& operator*=(int num) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] *= num;
            }
        }
        return *this;
    }
    bool operator==(const Bigint& other) const {
        if (rows != other.rows || cols != other.cols) {
            return false;
        }
        for (int i = 0; i < other.rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                if (data[i][j] == other.data[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator!=(const Bigint& other) const {
        return !(*this == other);
    }
    bool operator<(const Bigint& other) const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] < other.data[i][j]) {
                    return true;
                }
                else if (data[i][j] > other.data[i][j]) {
                    return false;
                }
            }
        }
        if (rows < other.rows || (rows == other.rows && cols < other.cols)) {
            return true;
        }
        return false;
    }
    bool operator>(const Bigint& other) const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] > other.data[i][j]) {
                    return true;
                }
                else if (data[i][j] < other.data[i][j]) {
                    return false;
                }
            }
        }
        if (rows > other.rows || (rows == other.rows && cols > other.cols)) {
            return true;
        }

        return false;
    }
    friend std::ostream& operator<<(std::ostream& os, const Bigint& other) {

        for (int i = 0; i < other.rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                os << other.data[i][j] << ' ';
            }
            std::cout << '\n';
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, const Bigint& other) {
        for (int i = 0; i < other.rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                is >> other.data[i][j];
            }
        }
        return is;
    }
};
int main()
{
    Bigint matrix1(2, 2);
    Bigint matrix2(2, 2);
    std::cout << matrix1 << std::endl;
    std::cout << matrix2 << std::endl;
    std::cout << matrix1 * matrix2 << std::endl;
    if (matrix1 != matrix2) {
        std::cout << "Yep" << std::endl;
    }
    else {
        std::cout << "Nope" << std::endl;
    }
    return 0;
}
