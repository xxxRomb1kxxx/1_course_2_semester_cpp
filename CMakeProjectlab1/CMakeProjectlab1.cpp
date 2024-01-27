#include <iostream> 
#include <cmath>
#include "CMakeProjectlab1.h"
namespace mt {

	Circle::Circle(float x, float y, float r) {
		setup(x, y, r);
		std::cout << "Const" << std::endl;
	}
	Circle::~Circle() {
		std::cout << "Dest" << std::endl;
	}
	void Circle::setup(float x, float y, float r) {
		m_p.x = x;
		m_p.y = y;
		m_r = r;
	}
	bool Circle::check_r(float r) {
		if (r < 0) {
			std::cout << "R < 0" << std::endl;
			return false;
		}
		return true;
	}
	bool Circle::check_x_y(float x, float y) {
		if (x < 0 || y < 0) {
			std::cout << "x or y < 0" << std::endl;
			return false;
		}
		return true;
	}
	void Circle::area(float r) {
		float s;
		s = 3.14f * r * r;
		std::cout << s << std::endl;
	}
	void Circle::length(float r) {
		float s;
		s = (2.0f * 3.14f) * r;
		std::cout << s << std::endl;
	}
}


