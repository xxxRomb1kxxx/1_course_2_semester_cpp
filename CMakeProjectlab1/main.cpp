#include <iostream> 
#include <cmath>
#include "CMakeProjectlab1.h"
int main() {

	
		float x, y, r;
		std::cin >> x >> y >> r;
		mt::Circle c(x, y, r);
		c.setup(x, y, r);
		if (c.check_r(r) && c.check_x_y(x,y)) {
			c.area(r);
			c.length(r);
		}
		else {
			std::cout << "Error" << std::endl;
		}
	
	return 0;
}