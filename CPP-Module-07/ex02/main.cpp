#include "Array.hpp"

int main()
{
    std::cout << "----- INT ARRAY -----\n";

    Array<int> a(5);

    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;

    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";

    std::cout << "\n\n----- COPY CONSTRUCTOR -----\n";

    Array<int> b(a);

    b[0] = 123;

    std::cout << "Original:\n";
    std::cout << a[0] << std::endl;

    std::cout << "Copy:\n";
    std::cout << b[0] << std::endl;

    std::cout << "\n----- ASSIGNMENT OPERATOR -----\n";

    Array<int> c;
    c = a;

    c[1] = 456;

    std::cout << "Original:\n";
    std::cout << a[1] << std::endl;

    std::cout << "Assigned copy:\n";
    std::cout << c[1] << std::endl;

    std::cout << "\n----- EXCEPTION TEST -----\n";

    try
    {
        std::cout << a[100] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught!" << std::endl;
    }

    std::cout << "\n----- STRING ARRAY -----\n";

    Array<std::string> words(2);

    words[0] = "CPP-Module-07";
    words[1] = "Templates";

    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << std::endl;

    return (0);
}