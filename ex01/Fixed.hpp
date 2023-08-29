#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
private:
	int	fp_value;
	static const int fract_bits = 8;
public:
//Constructors
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& copy);
//Destructor
	~Fixed();
//Operators
	Fixed	&operator=(const Fixed &src);
//Methods
	float	toFloat(void)const;
	int		toInt(void)const;
//Getter
	int		getRawBits( void ) const;
//Setter
	void	setRawBits( int const raw );
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif