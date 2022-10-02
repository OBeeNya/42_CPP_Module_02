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

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:

		int					_fixed;
		static const int	_bits;

};

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs);

#endif
