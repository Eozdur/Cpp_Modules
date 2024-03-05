#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixed_values = 0;
}
Fixed::Fixed(const Fixed &r)
{
    *this = r;
}
Fixed::~Fixed()
{
}
Fixed::Fixed(const int number) 
{
	this->fixed_values = (number * (1 << this->bits));
}

Fixed::Fixed(const float number) 
{
	this->fixed_values = roundf(number * (1 << this->bits));
}

Fixed &Fixed::operator = (Fixed const& fixed)
{
    if(this == &fixed)
        return *this;
    this->fixed_values = fixed.getRawBits();
    return(*this);
}

int Fixed::getRawBits(void) const
{
    return (this->fixed_values);
}
float Fixed::toFloat(void)const
{
    return((float)this->fixed_values / (float)(1 << this->bits));
}
int Fixed::toInt(void)const
{
    return(this->fixed_values / (1 << this->bits));
}
void Fixed::setRawBits(int const raw)
{
    this->fixed_values = raw;
}
std::ostream &operator<<(std::ostream &output, const Fixed &obj)//obj write to output
{
    output << obj.toFloat();
    return (output);
}
bool	Fixed::operator>(Fixed const& fixed) const
{
	return (this->fixed_values > fixed.getRawBits());
}

bool	Fixed::operator>=(Fixed const& fixed) const
{
	return (this->fixed_values >= fixed.getRawBits());
}

bool	Fixed::operator<(Fixed const& fixed) const
{
	return (this->fixed_values < fixed.getRawBits());
}

bool	Fixed::operator<=(Fixed const& fixed) const
{
	return (this->fixed_values <= fixed.getRawBits());
}

bool	Fixed::operator==(Fixed const& fixed) const
{
	return (this->fixed_values == fixed.getRawBits());
}

bool	Fixed::operator!=(Fixed const& fixed) const
{
	return (this->fixed_values != fixed.getRawBits());
}

Fixed	Fixed::operator+(Fixed const& fixed) 
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(Fixed const& fixed) 
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(Fixed const& fixed) 
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(Fixed const& fixed) 
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed	&Fixed::operator++() 
{
	this->fixed_values++;
	return (*this);
}

Fixed	Fixed::operator++(int) 
{
	Fixed	ret(this->toFloat());
	this->fixed_values++;
	return (ret);
}

Fixed	&Fixed::operator--() 
{
	this->fixed_values--;
	return (*this);
}

Fixed	Fixed::operator--(int) 
{
	Fixed	ret(this->toFloat());
	this->fixed_values--;
	return (ret);
}

Fixed	&Fixed::max(Fixed& a, Fixed& b) 
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::min(Fixed& a, Fixed& b) 
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed&a, const Fixed& b) 
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed&a, const Fixed& b) 
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}