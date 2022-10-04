#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void):
	_fixed(0)
{
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
	return ;
}

Fixed::Fixed(const int i):
	_fixed(i * (1 << Fixed::_bits))
{
	return ;
}

Fixed::Fixed(const float f):
	_fixed((int)roundf(f * (1 << Fixed::_bits)))
{
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	this->_fixed = rhs.getRawBits();
	return (*this);
}

int	Fixed::operator>(const Fixed &rhs)
{
	return (this->_fixed > rhs.getRawBits());
}

int	Fixed::operator<(const Fixed &rhs)
{
	return (this->_fixed < rhs.getRawBits());
}

int	Fixed::operator>=(const Fixed &rhs)
{
	return (this->_fixed >= rhs.getRawBits());
}

int	Fixed::operator<=(const Fixed &rhs)
{
	return (this->_fixed <= rhs.getRawBits());
}

int	Fixed::operator==(const Fixed &rhs)
{
	return (this->_fixed == rhs.getRawBits());
}

int	Fixed::operator!=(const Fixed &rhs)
{
	return (this->_fixed != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(__attribute__((unused))int u)
{
	Fixed	f(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (f);
}

Fixed	Fixed::operator--(__attribute__((unused))int u)
{
	Fixed	f(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (f);
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

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
}
