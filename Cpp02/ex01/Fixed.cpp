#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_values = 0;
}
Fixed::Fixed(const Fixed &r)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = r;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int number) 
{
	std::cout << "Int constructor called\n";
	this->fixed_values = (number * (1 << this->bits));
}

Fixed::Fixed(const float number) 
{
	std::cout << "Float constructor called\n";
	this->fixed_values = roundf(number * (1 << this->bits));
}

Fixed &Fixed::operator = (Fixed const& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
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
std::ostream &operator<<(std::ostream &output, const Fixed &obj)
{
    output << obj.toFloat();
    return (output);
}