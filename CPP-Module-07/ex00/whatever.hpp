#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename Type>
void    swap(Type& a, Type& b)
{
    Type tmp = a;
    a = b;
    b = tmp;
}

template <typename Type>
const Type& min(const Type& a, const Type& b)
{
    return (a < b) ? a : b;
}

template <typename Type>
const Type& max(const Type& a, const Type& b)
{
    return (a > b) ? a : b;
}

#endif