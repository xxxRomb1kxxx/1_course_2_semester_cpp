#include "CMakeProjectlab4.h"

int main() {
    // test all operators
    BigInt  first("11111111111111111111111111111111");
    BigInt second("22222222222222222222222222222222");
    std::cout << "first > second " << ((first > second) ? "True" : "False") << std::endl;
    std::cout << "first < second " << ((first < second) ? "True" : "False") << std::endl;
    std::cout << "first == second " << ((first == second) ? "True" : "False") << std::endl;
    std::cout << "first != second " << ((first != second) ? "True" : "False") << std::endl;
    BigInt sum = first + second;
    std::cout << "sum: " << sum << std::endl;
    sum += first;
    std::cout << "sum += first" << "    " << sum << std::endl;
    sum *= second;
    std::cout << "sum *= first" << "    " << sum << std::endl;
    BigInt mult = first * second;
    std::cout << "first * second" << "    " << mult << std::endl;
    return 0;
}