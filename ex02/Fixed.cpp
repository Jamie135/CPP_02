#include "Fixed.hpp"

Fixed::Fixed(): fp_value(0)
{
	// std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	// std::cout << "Int Constructor called" << std::endl;
	this->fp_value = input << this->fract_bits;
}

Fixed::Fixed(const float input)
{
	// std::cout << "Float Constructor called" << std::endl;
	this->fp_value = roundf(input * (1 << this->fract_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Fixed Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	// std::cout << "Fixed Deconstructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	// std::cout << "Fixed Assignation operator called" << std::endl;
	if (this != &src)
		this->fp_value = src.getRawBits();

	return *this;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->fp_value / (float)(1 << this->fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->fp_value >> this->fract_bits);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_value);
}

void Fixed::setRawBits(int const raw)
{
	this->fp_value = raw;
	// std::cout << "setRawBits member function called" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}