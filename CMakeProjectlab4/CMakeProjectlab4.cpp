#include "CMakeProjectlab4.h"
void BigInt::remove_zeros() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back(); // delete digit
    }
}
BigInt::BigInt() { // default constructor 
    digits.push_back(0);
}
BigInt::BigInt(const BigInt& other) = default; // copy construct

BigInt::BigInt(int num) { // from int to vector
    if (num == 0) {
        digits.push_back(0);
        return;
    }
    while (num != 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
}
BigInt::BigInt(const std::string& numStr) { // convert from string to int
    for (auto i = numStr.rbegin(); i != numStr.rend(); ++i) {
        auto digit = *i - '0';

        if (((digit > 9) || (digit < 0))) {
            if (i == --numStr.rend()) {
                digits[digits.size() - 1] *= -1;
                break;
            }
            else {
                throw std::invalid_argument("Error");
            }
        }
        digits.push_back(digit);
    }
    remove_zeros();
}
BigInt& BigInt::operator=(const BigInt& other) { // assignment operator by copying
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}
BigInt::~BigInt() = default; // destruct

BigInt BigInt::operator+(const BigInt& other) const {
    BigInt sum_result;
    int temp = 0;
    size_t max_size = std::max(digits.size(), other.digits.size());
    for (size_t i = 0; i < max_size || temp; ++i) {
        if (i == sum_result.digits.size())
            sum_result.digits.push_back(0);
        sum_result.digits[i] += temp + (i < digits.size() ? digits[i] : 0) + (i < other.digits.size() ? other.digits[i] : 0);
        temp = sum_result.digits[i] / 10;
        sum_result.digits[i] %= 10;
    }
    return sum_result;
}
BigInt& BigInt::operator+=(const BigInt& other) {
    *this = *this + other;

    remove_zeros();
    return *this;
}
BigInt& BigInt::operator*=(const BigInt& other) {
    *this = *this * other;
    return *this;
}
BigInt BigInt::operator*(const BigInt& other) const {
    BigInt sum_result;
    std::vector<int>::size_type m = digits.size(), n = other.digits.size();
    sum_result.digits.resize(m + n);
    for (std::vector<int>::size_type i = 0; i < m; ++i) {
        int carry = 0;
        for (std::vector<int>::size_type j = 0; j < n || carry; ++j) {
            auto sum = static_cast<long long>(sum_result.digits[i + j]) + static_cast<long long>(digits[i]) * (j < n ? other.digits[j] : 0) + carry;
            sum_result.digits[i + j] = static_cast<int>(sum % 10);
            carry = static_cast<int>(sum / 10);
        }
    }
    sum_result.remove_zeros();
    return sum_result;
}
bool BigInt::operator!=(const BigInt& other) const {
    return !(*this == other);
}
bool BigInt::operator<(const BigInt& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    for (std::vector<int>::size_type i = digits.size(); i-- > 0;) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;
}
bool BigInt::operator>(const BigInt& other) const {
    return other < *this;
}
bool BigInt::operator==(const BigInt& other) const {
    return digits == other.digits;
}
std::ostream& operator<<(std::ostream& os, const BigInt& num) {
    for (std::vector<int>::size_type i = num.digits.size(); i-- > 0;) {
        os << num.digits[i];
    }
    return os;
}
std::istream& operator>>(std::istream& is, BigInt& num) {
    std::string input;
    is >> input;
    num = BigInt(input);
    return is;
}