#include "Span.hpp"
#include <iostream>

int main()
{

    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // try {
    //     Span a(1);

    //     a.addNumber(110);
    //     a.addNumber(111);

    //     // a.shortestSpan();
    // }
    // catch (std::exception& e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    return (0);
}