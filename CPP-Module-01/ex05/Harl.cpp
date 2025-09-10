#include "Harl.hpp"
#include <iostream>

void Harl::debug( void ) {
    std::cout << "Debug: verifying function outputs and project flow." << std::endl;
}

void Harl::info( void ) {
    std::cout << "Info: program executing normally, all checks passed." << std::endl;
}

void Harl::warning( void ) {
    std::cerr << "Warning: unexpected behavior detected, review recommended." << std::endl;
}

void Harl::error( void ) {
    std::cerr << "Error: critical issue, project may fail if not addressed." << std::endl;
}

void Harl::complain( std::string level ) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    for (int i = 0; i < 4; i++)
        if (level == levels[i])
            return ((this->*functions[i])());
    std::cerr << "Unknown level. Use DEBUG, INFO, WARNING, or ERROR." << std::endl;
}
