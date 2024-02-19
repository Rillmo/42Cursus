#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;
		Point& operator=(const Point &p);
	public:
		Point();
		Point(const float n1, const float f2);
		Point(const Point &p);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
		static Fixed getAreaSize(Point const p1, Point const p2, Point const p3);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif