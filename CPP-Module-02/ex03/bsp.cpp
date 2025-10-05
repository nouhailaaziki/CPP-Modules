#include "Point.hpp"

static Fixed cross(Point const &a, Point const &b, Point const &p)
{
    return (b.getX() - a.getX()) * (p.getY() - a.getY()) 
         - (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross1 = cross(a, b, point);
    Fixed cross2 = cross(b, c, point);
    Fixed cross3 = cross(c, a, point);

    // Check if all are positive or all are negative
    bool has_neg = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
    bool has_pos = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);

    if (has_neg && has_pos)
        return (false);  // outside or on edge
    if (cross1 == 0 || cross2 == 0 || cross3 == 0)
        return (false);  // on edge or vertex
    return (true);  // inside
}
