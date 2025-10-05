#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed {
    private:
        int                 _raw;
        static const int    _fractionalBits = 8;

    public:
        Fixed();                          // default constructor
        Fixed(int nbr);                   // int constructor
        Fixed(float nbr);                 // float constructor
        Fixed(const Fixed& object);       // copy constructor
        Fixed& operator=(const Fixed&);   // copy assignment
        ~Fixed();                         // destructor

        bool    operator<(const Fixed& obj) const;
        bool    operator>(const Fixed& obj) const;
        bool    operator>=(const Fixed& obj) const;
        bool    operator<=(const Fixed& obj) const;
        bool    operator==(const Fixed& obj) const;
        bool    operator!=(const Fixed& obj) const;
        
        Fixed   operator+(const Fixed& other) const;
        Fixed   operator-(const Fixed& other) const;
        Fixed   operator*(const Fixed& other) const;
        Fixed   operator/(const Fixed& other) const;
        
        Fixed&  operator++();      // pre-increment (++a)
        Fixed   operator++(int);   // post-increment (a++)
        Fixed&  operator--();      // pre-decrement (--a)
        Fixed   operator--(int);   // post-decrement (a--)
        
        static Fixed&       min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed&       max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        
        float   toFloat(void) const;
        int     toInt(void) const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

// operator<< overload
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif