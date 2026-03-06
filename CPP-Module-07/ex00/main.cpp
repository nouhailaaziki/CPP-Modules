#include "whatever.hpp"

int main()
{
    int a = 6;
    int b = 8;

    std::cout << "Before swap:\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n\n";

    swap(a, b);

    std::cout << "After swap:\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n\n";

    std::cout << "min(a, b) = " << min(a, b) << "\n";
    std::cout << "max(a, b) = " << max(a, b) << "\n";

    return 0;
}