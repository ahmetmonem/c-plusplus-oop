#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete  meta;
    delete  j;
    delete  i;
    std::cout << "!!!!!:::::NOW WRONG::::!!!!!"<< std::endl;

    const WrongAnimal *WA = new WrongAnimal();
    const WrongAnimal *WCat = new WrongCat();
    std::cout << "WrongCat Type: " << WCat->getType() << " " << std::endl;
    WA->makeSound();
    WCat->makeSound();

    delete  WA;
    delete  WCat;

    return 0;
}