#pragma once

#include "InterfaceGameState.h"
#include <vector>
#include <string>

class MenuState : public InterfaceGameState
{
public:
	MenuState();
	virtual ~MenuState();

	virtual void Load();
	virtual void UnLoad();
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	std::vector<std::string> menuItems;
	int menuSelectedIndex = 0;

private:
};