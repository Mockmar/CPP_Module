
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	AAnimal		*faune[20];
	const AAnimal* j = new Dog();
	const AAnimal* k = new Cat();
	size_t i;

	// AAnimal A;
	// std::cout << A.getType() << std::endl;
	
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