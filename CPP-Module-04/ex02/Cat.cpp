#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "[Cat] created\n";
	brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "[Cat] copied\n";
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
	{
	    Animal::operator=(other);
	    delete brain;
	    brain = new Brain(*other.brain);
	}
    std::cout << "[Cat] assigned\n";
    return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!\n";
}

void Cat::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    return (brain->getIdea(index));
}

Cat::~Cat()
{
	std::cout << "[Cat] destroyed\n";
	delete brain;
}
