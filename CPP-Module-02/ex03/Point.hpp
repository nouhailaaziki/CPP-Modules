#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed x;
    const Fixed y;
    Point& operator=(const Point& other);  // declared, not defined

public:
    Point();                              // default constructor
    Point(float a, float b);              // constructor with coordinates
    Point(const Point& other);            // copy constructor
    ~Point();                             // destructor

    Fixed getX() const;
    Fixed getY() const;
};

// BSP function declaration
bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif
