#include "Fixed.hpp"
#include <iostream>

const int   Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _fixedPointValue(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& object)
{
    std::cout << "Copy constructor called\n";
    this->_fixedPointValue = object._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_fixedPointValue = other._fixedPointValue;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}
