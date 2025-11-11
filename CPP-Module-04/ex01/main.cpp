#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  std::cout << "----- Correct Polymorphism -----\n";
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << j->getType() << std::endl;
  std::cout << i->getType() << std::endl;

  i->makeSound();    // Meow
  j->makeSound();    // Woof
  meta->makeSound(); // Generic animal sound

  delete meta;
  delete j;
  delete i;

  std::cout << "\n----- Wrong Polymorphism -----\n";
  const WrongAnimal *wa = new WrongAnimal();
  const WrongAnimal *wc = new WrongCat();

  wc->makeSound();
  wa->makeSound();

  delete wa;
  delete wc;

  std::cout << "\n----- Animal Array Test -----\n";

  Animal *animals[10];

  for (int i = 0; i < 5; i++)
    animals[i] = new Dog();
  for (int i = 5; i < 10; i++)
    animals[i] = new Cat();

  for (int i = 0; i < 10; i++)
    delete animals[i];

  std::cout << "\n----- Deep Copy Test -----\n";

  Dog original;
  original.setIdea(0, "I want food");

  Dog copy = original;
  copy.setIdea(0, "I want sleep");

  std::cout << "Original idea: " << original.getIdea(0) << std::endl;
  std::cout << "Copy idea:     " << copy.getIdea(0) << std::endl;
  return (0);
}
