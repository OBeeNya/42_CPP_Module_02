#include "Point.hpp"

float	sign(Point point, Point a, Point b)
{
	return ((point.getXFloat() - b.getXFloat()) * (a.getYFloat() \
		- b.getYFloat()) - (a.getXFloat() - b.getXFloat()) * (point.getYFloat() \
		- b.getYFloat()));
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	float	d1;
	float	d2;
	float	d3;
	bool	neg;
	bool 	pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return (!(neg && pos));
}

int	main(int ac, char **av)
{
	Point	a(0.0, 0.0);
	Point	b(8.345, 0.0);
	Point	c(0.0, 6.345);

	Point	p0(2.1234, -0.1);
	std::cout << "p0 should not be in the triangle" << std::endl;
	if (bsp(a, b, c, p0))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point is not inside the triangle." << std::endl;
	std::cout << std::endl;

	Point	p1(-2.1234, 1345);
	std::cout << "p1 should not be in the triangle" << std::endl;
	if (bsp(a, b, c, p1))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point is not inside the triangle." << std::endl;
	std::cout << std::endl;


	Point	p2(-1111111111111, 2);
	std::cout << "p2 should not be in the triangle" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point is not inside the triangle." << std::endl;
	std::cout << std::endl;


	Point	p3(2, 2.00000001);
	std::cout << "p3 should be in the triangle" << std::endl;
	if (bsp(a, b, c, p3))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point is not inside the triangle." << std::endl;
	std::cout << std::endl;


	Point	p4(-0, -0);
	std::cout << "p4 should be in the triangle" << std::endl;
	if (bsp(a, b, c, p4))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point is not inside the triangle." << std::endl;
	std::cout << std::endl;


	Point	p5(0, 4);
	std::cout << "p5 should be in the triangle" << std::endl;
	if (bsp(a, b, c, p5))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point is not inside the triangle." << std::endl;
	std::cout << std::endl;

	return (0);
}
