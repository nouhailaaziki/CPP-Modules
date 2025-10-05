#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _raw(0) {}

Fixed::Fixed(int nbr) : _raw(nbr << _fractionalBits) {}

Fixed::Fixed(float nbr) : _raw(roundf(nbr * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& object) : _raw(object._raw) {}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_raw = other._raw;
    return (*this);
}

Fixed::~Fixed() {}

bool    Fixed::operator<(const Fixed& obj) const { return this->_raw < obj._raw; }

bool    Fixed::operator>(const Fixed& obj) const { return this->_raw > obj._raw; }

bool    Fixed::operator<=(const Fixed& obj) const { return this->_raw <= obj._raw; }

bool    Fixed::operator>=(const Fixed& obj) const { return this->_raw >= obj._raw; }

bool    Fixed::operator==(const Fixed& obj) const { return this->_raw == obj._raw; }

bool    Fixed::operator!=(const Fixed& obj) const { return this->_raw != obj._raw; }

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed res;
    res.setRawBits(this->_raw + other._raw);
    return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed res;
    res.setRawBits(this->_raw - other._raw);
    return (res);
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed res;
    long tmp = (long)this->_raw * (long)other._raw;
    res.setRawBits(tmp >> _fractionalBits);
    return (res);
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other._raw == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    Fixed res;
    long tmp = ((long)this->_raw << _fractionalBits) / other._raw;
    res.setRawBits(tmp);
    return (res);
}

Fixed&  Fixed::operator++() { this->_raw++; return (*this); }

Fixed   Fixed::operator++(int) { Fixed temp(*this); this->_raw++; return (temp); }

Fixed&  Fixed::operator--() { this->_raw--; return (*this); }

Fixed   Fixed::operator--(int) { Fixed temp(*this); this->_raw--; return (temp); }

Fixed&       Fixed::min(Fixed& a, Fixed& b)
{
    if (a._raw < b._raw)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a._raw < b._raw)
        return (a);
    else
        return (b);
}

Fixed&       Fixed::max(Fixed& a, Fixed& b)
{
    if (a._raw > b._raw)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a._raw > b._raw)
        return (a);
    else
        return (b);
}
 
int     Fixed::toInt(void) const { return (this->_raw >> _fractionalBits); }

float   Fixed::toFloat(void) const { return ((float)this->_raw / (1 << this->_fractionalBits)); }

int     Fixed::getRawBits(void) const { return (this->_raw); }

void    Fixed::setRawBits(int const raw) { this->_raw = raw; }

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}
