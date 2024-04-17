
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal*		meta = new Animal();
	const Animal*		dog = new Dog();
	const Animal*		cat = new Cat();
	const WrongAnimal*	wrong_cat = new WrongCat();

	std::cout << std::endl;

	std::cout << meta->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << wrong_cat->getType() << std::endl;

	std::cout << std::endl;

	meta->makeSound();
	dog->makeSound();
	cat->makeSound();
	wrong_cat->makeSound();

	std::cout << std::endl;
    
	delete meta;
	delete dog;
	delete cat;
	delete wrong_cat;

	return (0);
}