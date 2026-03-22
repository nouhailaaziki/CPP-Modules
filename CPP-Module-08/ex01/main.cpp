#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Subject Test Case
    std::cout << "--- Subject Test ---" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Heavy Load Test Case (15,000 elements)
    std::cout << "\n--- Heavy Load Test (15,000 elements) ---" << std::endl;
    try
    {
        unsigned int totalElements = 15000;
        Span big(totalElements);
        std::vector<int> numbers;

        std::srand(static_cast<unsigned int>(std::time(NULL)));
        for (unsigned int i = 0; i < totalElements; i++)
        {
            numbers.push_back(std::rand());
        }

        big.addRange(numbers.begin(), numbers.end());

        std::cout << "Shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Longest: " << big.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Exception Handling Test Case
    std::cout << "\n--- Exception Testing ---" << std::endl;
    try
    {
        Span small(2);
        small.addNumber(1);
        small.addNumber(2);
        small.addNumber(3); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    return (0);
}