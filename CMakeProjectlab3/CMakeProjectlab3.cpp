#include "CMakeProjectlab3.h"
#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t length;

public:
    // Базовый конструктор
    String() : data(nullptr), length(0) {}
    // Конструктор для инициализации строки
    String(const char* str) : data(nullptr), length(0) {
        if (str != nullptr) {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        }
    }
    // Оператор присваивания копированием
   String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            data = new char[other.length + 1];
            length = other.length;
            std::strcpy(data, other.data);
        }
        return *this;
    }
    
    /*
    void Swap(String& other)
    {
        std::swap(data, other.data);
        std::swap(length, other.length);
    }

    String& operator=(String other)
    {
        Swap(other);

        return *this;
    }
    */
    String(const String& other) : String(other.data) {

    }
    

    
    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        std::strcpy(result.data, data);
        std::strcat(result.data, other.data);
        return result;
    }
    String& operator+=(const String& other) {
        size_t newLength = length + other.length;
        char* newData = new char[newLength + 1];
        std::strcpy(newData, data);
        std::strcat(newData, other.data);
        delete[] data;
        data = newData;
        length = newLength;
        return *this;
    }
    char operator[](size_t index) const {
        if (index < std::strlen(data)) {
            return data[index];
        }
        else {
            throw std::out_of_range("Index out of range");
        }
    }
    char& operator[](size_t index) {
        if (index < std::strlen(data)) {
            return data[index];
        }
        else {
            static char nullChar = '\0';
            return nullChar;
        }
    }
    bool operator<(const String& other) const {
        return std::strcmp(data, other.data) < 0;
    }

    bool operator>(const String& other) const {
        return std::strcmp(data, other.data) > 0;
    }

    bool operator==(const String& other) const {
        return std::strcmp(data, other.data) == 0;
    }
    // Деструктор
    ~String() {
        if (data != nullptr) {
            delete[] data;
        }  
    }
    //вывод
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }
    //ввод
    friend std::istream& operator>>(std::istream& is, String& str) {
        char buffer[4096];
        is >> buffer;
        str = String(buffer);
        return is;
    }

    size_t find(char c) const {
        if (data != nullptr) {
            int cnt =0;
            for (size_t i = 0; i < std::strlen(data); ++i) {
                if (data[i] == c) {
                    cnt += 1;
                }
            }
            return cnt;
        }
        return std::string::npos; 
    }
    size_t ln() const {
        size_t len = 0;
        while (data != nullptr && data[len] != '\0') {
            ++len;
        }
        return len;
    }
    const char* c_str() const {
        return (data != nullptr) ? data : ""; 
    }
    char at(size_t index) const {
        if (data == nullptr || index >= ln()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    char& at(size_t index) {
        if (data == nullptr || index >= ln()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

};

int main() {
    String str1("TRAVIS");
    String str2("SCOTT");
    String str3 = str1;
    //std::cout << str1 << std::endl;
    //std::cout << str3 << std::endl;
    String swag = str1 + str2;
    std::cout << "operator +:" << "  " << swag << std::endl;
    str2 += str1;
    std::cout << "operator +=:" << "  " << str2 << std::endl;
    std::cout << "Index:" << "  " << str1[0] << std::endl;
    if (str1 > str2) {
        std::cout <<"str1 > str2" << " " << " - Yes,sir" << std::endl;
    }
    char search = 'V';
    size_t index = str1.find(search);
    std::cout <<search << " " << str1 << " - " << index << std::endl;
    size_t l = str1.ln();
    std::cout << "Length - " << str1 << " - " << l << std::endl;
    const char* cString = str1.c_str();
    std::cout << "C_str " << str1 << " - " << cString << std::endl;
    try {
        char character = str1.at(5);
        std::cout << "index 5: " << character << std::endl;
        str1.at(3) = '!';
        std::cout << "Modified string: " << str1.c_str() << std::endl;
    }catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Error: wtf " << std::endl;
    }
    return 0;
}