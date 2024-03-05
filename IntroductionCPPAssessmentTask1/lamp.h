#pragma once
#include "Item.h"
class Lamp : public Item
{
public:
	Lamp();
	~Lamp();

	void Description() const override;
	void Use() override;

private:
	bool turnedOn;
};

