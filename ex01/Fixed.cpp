#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void):
	_fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int i):
	_fixed(i * (1 << Fixed::_bits))
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float f):
	_fixed((int)roundf(f * (1 << Fixed::_bits)))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

void	Fixed::setRawBits(const int raw)
{
	this->_fixed = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixed / (1 << Fixed::_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixed / (1 << Fixed::_bits));
}

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs)
{
	return (o << rhs.toFloat());
}
