#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename Type, typename Func>
void    iter(Type* arr, const size_t len, Func func)
{
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

#endif