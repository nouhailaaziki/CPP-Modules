#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    try
    {
        std::vector<int>::iterator it = easyfind(a, 3);
        std::cout << "The value was found, which is: " << *it << std::endl;
        it = easyfind(a, 5);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}