#pragma once
#include "Item.h"
class BoxOfDonuts : public Item
{
public:
	BoxOfDonuts();
	~BoxOfDonuts();

	void Description() const override;
	void Use() override;

private:
	int count;
};

