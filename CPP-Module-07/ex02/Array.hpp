#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename Type>
class Array
{
    private:
        Type*          store;
        unsigned int   _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array<Type>& operator=(const Array<Type>& other);
        ~Array();

        Type& operator[](unsigned int index);
        const Type& operator[](unsigned int index) const;

        unsigned int size() const;
};

# include "Array.tpp"

#endif