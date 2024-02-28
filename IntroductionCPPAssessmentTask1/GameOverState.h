#pragma once

#include "InterfaceGameState.h"
#include <string>

class GameOverState : public InterfaceGameState
{
public:
	GameOverState();
	virtual ~GameOverState();

	virtual void Load();
	virtual void UnLoad();
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	std::string name ="";

private:
};