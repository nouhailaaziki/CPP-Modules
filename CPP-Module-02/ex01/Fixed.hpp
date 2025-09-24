#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed {
    private:
        int                 _raw;
        static const int    _fractionalBits;

    public:
        Fixed();                          // default constructor
        Fixed(int nbr);                   // int constructor
        Fixed(float nbr);                 // float constructor
        Fixed(const Fixed& object);       // copy constructor
        Fixed& operator=(const Fixed&);   // copy assignment
        ~Fixed();                         // destructor

        int     toInt(void) const;
        float   toFloat(void) const;
};

// operator<< overload
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif