#include <iostream>
namespace mt {
	struct Point {
		float x;
		float y;
	};
	class Circle {
		float m_r;
		Point m_p;

	public:
		Circle(float x, float y, float r);
		~Circle();

		void setup(float x, float y, float r);
		bool check_r(float r);
		bool check_x_y(float x, float y);
		void area(float r);
		void length(float r);

	};
}
