#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "[Dog] created\n";
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "[Dog] copied\n";
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
	{
	    Animal::operator=(other);
	    delete brain;
	    brain = new Brain(*other.brain);
	}
    std::cout << "[Dog] assigned\n";
    return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!\n";
}

void Dog::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return (brain->getIdea(index));
}

Dog::~Dog()
{
	std::cout << "[Dog] destroyed\n";
	delete brain;
}
