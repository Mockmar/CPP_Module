
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal		*faune[20];
	const Animal* j = new Dog();
	const Animal* k = new Cat();
	Dog	basic;
	{
	Dog	tmp = basic;
	}
	
	size_t i;

	delete j;
	delete k;

	for (i = 0; i < 10; i++)
	{
		faune[i] = new Dog();
		faune[i]->makeSound();
	}
	for (i = 10; i < 20; i++)
	{
		faune[i] = new Cat();
		faune[i]->makeSound();
	}
	for(i = 0; i < 20; i++)
	{
		delete(faune[i]);
	}
	return (0);
}