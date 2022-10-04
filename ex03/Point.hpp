#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{

	public:

		Point(void);
		Point(const float x, const float y);
		Point(const Point &src);
		~Point(void);

		Point	&operator=(const Point &rhs);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
		float	getXFloat(void) const;
		float	getYFloat(void) const;

	private:

		const Fixed	_x;
		const Fixed	_y;

};

#endif
