#include <iostream>
#include <string>

int main()
{
    std::string     brain = "HI THIS IS BRAIN";
    std::string*    stringPTR = &brain;
    std::string&    stringREF = brain;

    // Print addresses
    std::cout << "Address of brain:               " << &brain << std::endl;
    std::cout << "Address held by stringPTR:      " << stringPTR << std::endl;
    std::cout << "Address held by stringREF:      " << &stringREF << std::endl;

    std:: cout << "==============================================" << std::endl;

    // Print values
    std::cout << "Value of brain:               " << brain << std::endl;
    std::cout << "Value pointed by stringPTR:   " << *stringPTR << std::endl;
    std::cout << "Value referred by stringREF:  " << stringREF << std::endl;
}
