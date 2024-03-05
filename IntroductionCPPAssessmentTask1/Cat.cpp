#include "Cat.h"
#include <iostream>

Cat::Cat()
{
	purring = true;
}

Cat::~Cat()
{
	//no new memory declared
}

void Cat::Description() const
{
	if (purring)
	{
		std::cout << "Wow it's a cat it's purring" << std::endl;
	}
	else
	{
		std::cout << "Wow it's a cat it's not purring" << std::endl;
	}
}

void Cat::Use()
{
	std::cout << "You tried to use a cat? Really??" << std::endl;
	purring = !purring;
}
