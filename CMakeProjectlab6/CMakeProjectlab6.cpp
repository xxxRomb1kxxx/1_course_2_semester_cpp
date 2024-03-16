#include <iostream>
#include <algorithm> 
#include <cstdlib>
#include "CMakeProjectlab6.h"

void Vector<bool>::make_array_n(size_t size) {
    array_n = new char[size]();
}
char* Vector<bool>::copy_array_n() {
    auto copy = new char[size_m]();
    std::copy(array_n, array_n + size_m, copy);
    return copy;
}
void Vector<bool>::copy_to_array_n(char* array_nay, size_t size) {
    std::copy(array_nay, array_nay + size, array_n);
}
void Vector<bool>::expand_array_n() {
    auto newsize_m = size_m + 1;
    auto temp_copy = copy_array_n();
    delete_array_n();
    make_array_n(newsize_m);
    copy_to_array_n(temp_copy, size_m);
    delete[] temp_copy;

    size_m = newsize_m;
}

void Vector<bool>::delete_array_n() {
    delete[] array_n;
}

Vector<bool>::Vector(size_t bits_count) {
    if (bits_count == 0) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    cnt_bit = bits_count;
    size_m = (bits_count - 1) / 8 + 1;
    make_array_n(size_m);
}
Vector<bool>::~Vector() {
    delete_array_n();
}
Vector<bool>::Vector(const Vector& other) {
    make_array_n(other.size_m);
    copy_to_array_n(other.array_n, other.size_m);
    cnt_bit = other.cnt_bit;
}
Vector<bool>& Vector<bool>::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }
    size_m = other.size_m;
    delete_array_n();
    make_array_n(size_m);
    copy_to_array_n(other.array_n, other.size_m);
}
bool Vector<bool>::get(size_t index) {
    auto position = std::make_pair((index) / 8, index % 8); // for example 3 pair(0,4) -> 
    return (array_n[position.first] >> (8 - 1 - position.second)) & 1; // 0 >> (3) -> 0 >> 4 , & 1 -> return 0

}
bool Vector<bool>::operator[](size_t index) {
    return get(index);
}

size_t Vector<bool>::size() const {
    return cnt_bit;
}
void Vector<bool>::set(size_t index, bool value) {
    auto position = std::make_pair((index) / 8, index % 8); // for example 4 pair(0,4) -> 
    if (value) {
        array_n[position.first] = array_n[position.first] | (1 << (8 - 1 - position.second)); //  1 << (8-1-4) -> 0001000
    } 
    else
        array_n[position.first] = array_n[position.first] & ~(1 << (8 - 1 - position.second));  // 1 << (8-1-4) -> 0001000, ~ -> 1110111 -> 
}

void Vector<bool>::pushBack(bool value) {
    if (cnt_bit % 8 == 0) {
        expand_array_n();
    }
    set(cnt_bit, value);
    cnt_bit++;
}
void Vector<bool>::insert(size_t index, bool value) {
    if (cnt_bit % 8 == 0) {
        expand_array_n();
    }
    cnt_bit++;
    for (auto last_index = cnt_bit - 1; last_index > index; last_index--) {
        set(last_index, get(last_index - 1));
    }
    set(index, value);
}

void Vector<bool>::erase(size_t index) {
    cnt_bit--;
    for (auto first_index = index; first_index < cnt_bit; first_index++) {
        set(first_index, get(first_index + 1));
    }
    set(cnt_bit, false);
}

void Vector<bool>::print() {
    for (size_t i = 0; i < size(); i++) {
        std::cout << (*this)[i];
    }
    std::cout << std::endl;
}

