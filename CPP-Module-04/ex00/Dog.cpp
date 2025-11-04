#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "[Dog] created\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "[Dog] copied\n";
}

Dog& Dog::operator=(const Dog& other)
{
    Animal::operator=(other);
    std::cout << "[Dog] assigned\n";
    return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!\n";
}

Dog::~Dog()
{
	std::cout << "[Dog] destroyed\n";
}
