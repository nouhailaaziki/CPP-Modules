#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "[WrongCat] created\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "[WrongCat] copied\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    WrongAnimal::operator=(other);
    std::cout << "[WrongCat] assigned\n";
    return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Meow!\n";
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] destroyed\n";
}
