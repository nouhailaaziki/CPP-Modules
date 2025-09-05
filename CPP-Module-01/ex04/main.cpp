#include "Replacer.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./program <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    Replacer replacer(argv[1], argv[2], argv[3]);
    if (replacer.getS1().empty())
    {
        std::cerr << "Error: s1 should not be empty!" << std::endl;
        return (1);
    }
    if (!replacer.replaceFileContent())
        return (std::cerr << "Error processing file" << std::endl, 1);
    return (0);
}
