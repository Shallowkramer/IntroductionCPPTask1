#include "Lamp.h"
#include <iostream>

Lamp::Lamp()
{
	turnedOn = false;
}

Lamp::~Lamp()
{
	//no new memory declared
}

void Lamp::Description() const
{
	if (turnedOn)
	{
		std::cout << "Not much too say about a lamp, but it's on!" << std::endl;

	}
	else
	{
		std::cout << "Not much too say about a lamp..." << std::endl;
	}
}

void Lamp::Use()
{
	std::cout << "You flick the switch on the lamp, not much seems to happen..." << std::endl;
	turnedOn = !turnedOn;
}
