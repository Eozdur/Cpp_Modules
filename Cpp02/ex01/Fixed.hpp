#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixed_values;
        const static int bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &r);
        ~Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed &operator=(const Fixed &r);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void)const;
        int toInt(void)const;
};
std::ostream &operator<<(std::ostream &output, const Fixed &obj);
#endif