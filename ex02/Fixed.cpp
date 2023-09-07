#include "Fixed.hpp"

//Constructor/Destructor
Fixed::Fixed(): fp_value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fp_value = input << this->fract_bits;
}

Fixed::Fixed(const float input)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fp_value = roundf(input * (1 << this->fract_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Fixed Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	// std::cout << "Fixed deconstructor called" << std::endl;
}

//Equal Operator
Fixed	&Fixed::operator=(const Fixed &src)
{
	// std::cout << "Fixed assignation operator called" << std::endl;
	if (this != &src)
		this->fp_value = src.getRawBits();

	return *this;
}

//Comparison Operators
bool	Fixed::operator>(Fixed n) const
{
	return (this->toFloat() > n.toFloat());
}

bool	Fixed::operator<(Fixed n) const
{
	return (this->toFloat() < n.toFloat());
}

bool	Fixed::operator>=(Fixed n) const
{
	return (this->toFloat() >= n.toFloat());
}

bool	Fixed::operator<=(Fixed n) const
{
	return (this->toFloat() <= n.toFloat());
}

bool	Fixed::operator==(Fixed n) const
{
	return (this->toFloat() == n.toFloat());
}

bool	Fixed::operator!=(Fixed n) const
{
	return (this->toFloat() != n.toFloat());
}

//Arithmetic Operators
float	Fixed::operator+(Fixed n) const
{
	return (this->toFloat() + n.toFloat());
}

float	Fixed::operator-(Fixed n) const
{
	return (this->toFloat() - n.toFloat());
}

float	Fixed::operator*(Fixed n) const
{
	return (this->toFloat() * n.toFloat());
}

float	Fixed::operator/(Fixed n) const
{
	return (this->toFloat() / n.toFloat());
}

//Pre-increment Operators
Fixed	Fixed::operator++()
{
	this->fp_value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->fp_value--;
	return (*this);
}

//Post-increment Operators
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	// i = this->fp_value;
	++this->fp_value;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	// i = this->fp_value;
	--this->fp_value;
	return (tmp);
}

//Public Methods
float	Fixed::toFloat(void)const
{
	return ((float)this->fp_value / (float)(1 << this->fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->fp_value >> this->fract_bits);
}

Fixed	&Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1.toFloat() <= n2.toFloat())
		return (n1);
	else
		return (n2);
}

const Fixed	&Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1.toFloat() <= n2.toFloat())
		return (n1);
	else
		return (n2);
}

Fixed	&Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1.toFloat() >= n2.toFloat())
		return (n1);
	else
		return (n2);
}

const Fixed	&Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1.toFloat() >= n2.toFloat())
		return (n1);
	else
		return (n2);
}

//Getter
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_value);
}

//Setter
void Fixed::setRawBits(int const raw)
{
	this->fp_value = raw;
	// std::cout << "setRawBits member function called" << std::endl;
}

//ostream Operator
std::ostream	&operator<<(std::ostream &o, Fixed const &n)
{
	o << n.toFloat();
	return (o);
}