#include "whatever.hpp"

int main()
{
    /**************** SUBJECT TEST CASES *****************/
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    /**************** PERSONAL TEST CASES ****************/
    // int a = 6;
    // int b = 8;

    // std::cout << "Before swap:\n";
    // std::cout << "a = " << a << "\n";
    // std::cout << "b = " << b << "\n\n";

    // swap(a, b);

    // std::cout << "After swap:\n";
    // std::cout << "a = " << a << "\n";
    // std::cout << "b = " << b << "\n\n";

    // std::cout << "min(a, b) = " << min(a, b) << "\n";
    // std::cout << "max(a, b) = " << max(a, b) << "\n";

    return (0);
}