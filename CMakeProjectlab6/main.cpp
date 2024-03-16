#include <iostream>
#include <algorithm> 
#include <cstdlib>
#include "CMakeProjectlab6.h"
int main() {
    Vector<bool> v(5);
    v.set(0, true);  
    v.set(1, true);  
    v.set(2, false);
    v.set(3, false); 
    v.set(4, true);
    v.pushBack(false);    
    v.pushBack(true);
    std::cout << "////////////////////////"<< std::endl;
    std::cout << "Vector - ";
    v.print();
    std::cout << "size" << " " << v.size() << std::endl;
    std::cout << "////////////////////////"<< std::endl;
    std::cout << "Inserted vector" << std::endl;
    v.insert(7, false);
    v.insert(7, true);
    std::cout << "size" << " " << v.size() << std::endl;
    std::cout << "Vector - ";
    v.print();
    std::cout << "////////////////////////"<< std::endl;
    std::cout << "Erased vector" << std::endl;
    v.erase(0);
    v.erase(0);
    std::cout << "size" << " " << v.size() << std::endl;
    std::cout << "Vector - ";
    v.print();
    std::cout << "////////////////////////" << std::endl;
    std::cout <<"v.get(4)"<< " " <<"-" << " " << v.get(4) << std::endl;
    std::cout << "v[4]" << " " << "-" << " "  << v[4] << std::endl;
    std::cout << "////////////////////////" << std::endl;
    return 0;
	
}