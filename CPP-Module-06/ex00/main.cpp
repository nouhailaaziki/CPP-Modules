#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    std::string input;
    if (argc != 2)
    {
	    std::cout << "Usage: ./convert <literal>\n";
	    return (1);
    }
    input = argv[1];
    ScalarConverter::convert(input);
}