#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int   Fixed::_fractionalBits = 8;

Fixed::Fixed() : _raw(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(int nbr)
{
    std::cout << "Int constructor called\n";
    _raw = nbr << _fractionalBits;
}

Fixed::Fixed(float nbr)
{
    std::cout << "Float constructor called\n";
    _raw = roundf(nbr * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& object)
{
    std::cout << "Copy constructor called\n";
    this->_raw = object._raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_raw = other._raw;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int     Fixed::toInt(void) const
{
    return (this->_raw >> _fractionalBits);
}

float   Fixed::toFloat(void) const
{
    return ((float)this->_raw / (1 << this->_fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return (os);
}
