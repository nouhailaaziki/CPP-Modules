#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include "easyfind.hpp"

int main(void)
{
    std::cout << "===== VECTOR TEST =====" << std::endl;
    std::vector<int> vec;
    vec.push_back(17);
    vec.push_back(2);
    vec.push_back(20);
    vec.push_back(5);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        easyfind(vec, 127);
        std::cout << "Found!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== LIST TEST =====" << std::endl;
    std::list<int> lst;
    lst.push_back(20);
    lst.push_back(5);
    lst.push_back(2);
    lst.push_back(17);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== DEQUE TEST =====" << std::endl;
    std::deque<int> deq;
    deq.push_back(5);
    deq.push_back(10);
    deq.push_back(15);
    deq.push_back(20);

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 15);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== CONST VECTOR TEST =====" << std::endl;
    std::vector<int> build_cvec;
    build_cvec.push_back(89);
    build_cvec.push_back(50);
    build_cvec.push_back(8);
    build_cvec.push_back(53);
    const std::vector<int> cvec(build_cvec);

    try
    {
        std::vector<int>::const_iterator it = easyfind(cvec, 8);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== DUPLICATE VALUES TEST =====" << std::endl;
    std::vector<int> dup;
    dup.push_back(13);
    dup.push_back(37);
    dup.push_back(13);
    dup.push_back(13);

    try
    {
        std::vector<int>::iterator it = easyfind(dup, 13);
        std::cout << "First occurrence found: " << *it << std::endl;
        std::cout << "Position: " << std::distance(dup.begin(), it) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}