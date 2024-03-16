#include <iostream>
#include <algorithm> 
#include <cstdlib>
template<typename T>
class Vector {};

template<>
class Vector<bool> {
private:
    char* array_n;
    size_t size_m;
    size_t cnt_bit;

    char* copy_array_n();
    void make_array_n(size_t size);
    void copy_to_array_n(char* array_nay, size_t size);
    void expand_array_n();
    void delete_array_n();
public:
    explicit Vector(size_t bits_count);
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    size_t size() const;
    bool get(size_t index);
    bool operator[](size_t index);
    void set(size_t index, bool value);
    void pushBack(bool value);
    void insert(size_t index, bool value);
    void erase(size_t index);
    void print();
};
