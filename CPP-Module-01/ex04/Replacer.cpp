#include "Replacer.hpp"
#include <iostream>
#include <fstream>

Replacer::Replacer(char *arg1, char *arg2, char *arg3)
    : s1(arg2), s2(arg3), in_filename(arg1),
    out_filename(std::string(arg1) + ".replace") 
{}


const std::string& Replacer::getS1(void) const {
    return (this->s1);
}

const std::string& Replacer::getS2(void) const {
    return (this->s2);
}

const std::string& Replacer::getInFilename(void) const {
    return (this->in_filename);
}

const std::string& Replacer::getOutFilename(void) const {
    return (this->out_filename);
}

bool Replacer::replaceFileContent() const
{
    std::ifstream inputFile(this->getInFilename().c_str());
    if (!inputFile.is_open()) {return (false);};
    std::ofstream outputFile(this->getOutFilename().c_str());
    if (!outputFile.is_open()) {return (inputFile.close(), false);};
    std::string line;
    size_t      pos;
    while (getline(inputFile, line))
    {
        pos = 0;
        while ((pos = line.find(this->getS1(), pos)) != std::string::npos)
        {
                line.erase(pos, this->getS1().length());
                line.insert(pos, this->getS2());
                pos += this->getS2().length();
        }
        outputFile << line;
        if (!inputFile.eof()) {outputFile << std::endl;};
    }
    inputFile.close();
    outputFile.close();
    return (true);
}
