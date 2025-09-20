#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits;

    public:
        Fixed();                          // default constructor
        Fixed(const Fixed& object);       // copy constructor
        Fixed& operator=(const Fixed&);   // copy assignment
        ~Fixed();                         // destructor

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};
#endif