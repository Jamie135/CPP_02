#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
private:
	int	fp_value;
	static const int fract_bits = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	~Fixed();
	Fixed	&operator=(const Fixed &src);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif