#pragma once
#include "Item.h"
class Dog : public Item
{
public:
	Dog();
	~Dog();

	void Description() const override;
	void Use() override;

private:
	bool isDog;
};

