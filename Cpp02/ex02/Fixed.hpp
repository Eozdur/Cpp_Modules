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
        Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		Fixed	operator+(Fixed const& fixed);
		Fixed	operator-(Fixed const& fixed);
		Fixed	operator*(Fixed const& fixed);
		Fixed	operator/(Fixed const& fixed);
		bool	operator>(Fixed const& fixed)const;
		bool	operator>=(Fixed const& fixed)const;
		bool	operator<(Fixed const& fixed)const;
		bool	operator<=(Fixed const& fixed)const;
		bool 	operator!=(Fixed const& fixed)const;
		bool	operator==(Fixed const& fixed)const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void)const;
        int toInt(void)const;
        static Fixed	&max(Fixed &a, Fixed &b);
		static Fixed	&min(Fixed &a, Fixed &b);
		const static Fixed	&max(const Fixed& a, const Fixed& b);
		const static Fixed	&min(const Fixed& a, const Fixed& b);
};
std::ostream &operator<<(std::ostream &output, const Fixed &obj);
#endif