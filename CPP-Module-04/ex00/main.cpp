#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  std::cout << "----- Correct Polymorphism -----\n";
  const Animal *meta = new Animal();
  const Animal *d = new Dog();
  const Animal *c = new Cat();

  std::cout << d->getType() << std::endl;
  std::cout << c->getType() << std::endl;

  d->makeSound();    // Woof
  c->makeSound();    // Meow
  meta->makeSound(); // Generic animal sound

  delete meta;
  delete d;
  delete c;

  std::cout << "\n----- Wrong Polymorphism -----\n";
  const WrongAnimal *wa = new WrongAnimal();
  const WrongAnimal *wc = new WrongCat();

  wc->makeSound();
  wa->makeSound();

  delete wa;
  delete wc;
  return (0);
}
