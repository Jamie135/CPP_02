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
	bool operator>(Fixed fixed)const;
	bool operator<(Fixed fixed)const;
	bool operator>=(Fixed fixed)const;
	bool operator<=(Fixed fixed)const;
	bool operator==(Fixed fixed)const;
	bool operator!=(Fixed fixed)const;
	float operator+(Fixed fixed)const;
	float operator-(Fixed fixed)const;
	float operator*(Fixed fixed)const;
	float operator/(Fixed fixed)const;
	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);
//Methods
	float	toFloat(void)const;
	int		toInt(void)const;
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
//Getter
	int		getRawBits( void ) const;
//Setter
	void	setRawBits( int const raw );
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif