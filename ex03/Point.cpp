#include "Point.hpp"

Point::Point(void):
	_x(Fixed(0)),
	_y(Fixed(0))
{
	return ;
}

Point::Point(const float x, const float y):
	_x(Fixed(x)),
	_y(Fixed(y))
{
	return ;
}

Point::Point(const Point &src):
	_x(src.getX()),
	_y(src.getY())
{
	return ;
}

Point::~Point(void)
{
	return ;
}

Point	&Point::operator=(const Point &rhs)
{
	(void)rhs;
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

float	Point::getXFloat(void) const
{
	return (this->_x.toFloat());
}

float	Point::getYFloat(void) const
{
	return (this->_y.toFloat());
}
