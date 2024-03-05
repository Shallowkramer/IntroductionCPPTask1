#include "BoxOfDonuts.h"
#include <iostream>

BoxOfDonuts::BoxOfDonuts()
{
	count = 13;
}

BoxOfDonuts::~BoxOfDonuts()
{
	//no new memory declared
}

void BoxOfDonuts::Description() const
{
	std::cout << "The strange box of donuts currently holds " << count << " donut(s)..." << std::endl;
}

void BoxOfDonuts::Use()
{
	if (count > 0)
	{
		std::cout << "Why would you eat a random donut you found, either way you eat one..." << std::endl;
		count--;
	}
	else
	{
		std::cout << "The box of donuts is now empty...how could you..." << std::endl;
	}
}
