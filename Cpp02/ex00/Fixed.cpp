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
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_values);
}
void Fixed::setRawBits(int const raw)
{
    this->fixed_values = raw;
}