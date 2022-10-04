#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{

	public:

		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed(void);

		Fixed	&operator=(const Fixed &rhs);

		int		operator>(const Fixed &rhs);
		int		operator<(const Fixed &rhs);
		int		operator>=(const Fixed &rhs);
		int		operator<=(const Fixed &rhs);
		int		operator==(const Fixed &rhs);
		int		operator!=(const Fixed &rhs);

		Fixed	operator+(const Fixed &rhs);
		Fixed	operator-(const Fixed &rhs);
		Fixed	operator*(const Fixed &rhs);
		Fixed	operator/(const Fixed &rhs);

		Fixed	operator++(void);
		Fixed	operator--(void);
		Fixed	operator++(__attribute__((unused))int u);
		Fixed	operator--(__attribute__((unused))int u);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

	private:

		int					_fixed;
		static const int	_bits;

};

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs);

#endif
