#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

// Non-const array version
template <typename Type>
void	iter(Type* arr, size_t len, void (*func)(Type&))
{
	size_t i = 0;

	while (i < len)
	{
		func(arr[i]);
		i++;
	}
}

// Const array version
template <typename Type>
void	iter(const Type* arr, size_t len, void (*func)(const Type&))
{
	size_t i = 0;

	while (i < len)
	{
		func(arr[i]);
		i++;
	}
}

#endif