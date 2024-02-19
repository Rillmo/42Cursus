#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float n1, const float n2) 
:_x(n1), _y(n2) {}

Point::Point(const Point &p)
:_x(p._x), _y(p._y)
{}

Point& Point::operator=(const Point &p)
{
	void(p._x);
	// const_cast<Fixed&>(_x) = p._x;
	// const_cast<Fixed&>(_y) = p._y;
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const{
	return _x;
}

Fixed Point::getY() const{
	return _y;
}

Fixed Point::getAreaSize(Point const p1, Point const p2, Point const p3) {
	Fixed tmp1(p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY());
	Fixed tmp2(p2.getX() * p1.getY() + p3.getX() * p2.getY() + p1.getX() * p3.getY());

	return Fixed((tmp1 - tmp2) / 2.0f);
}

Fixed abs(const Fixed& f) {
	if (f.getRawBits() < 0)
		return Fixed(f) * Fixed(-1);
	else
		return f;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed totalArea(abs(Point::getAreaSize(a, b, c)));
	Fixed areaABP(abs(Point::getAreaSize(a, b, point)));
	Fixed areaBCP(abs(Point::getAreaSize(b, c, point)));
	Fixed areaCAP(abs(Point::getAreaSize(c, a, point)));

	if (areaABP <= 0 || areaBCP <= 0 || areaCAP <= 0)
		return false;
	if (totalArea == areaABP + areaBCP + areaCAP)
		return true;
	return false;
}
