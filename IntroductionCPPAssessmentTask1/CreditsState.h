#pragma once

#include "InterfaceGameState.h"

class CreditsState : public InterfaceGameState
{
public:
	CreditsState();
	virtual ~CreditsState();

	virtual void Load();
	virtual void UnLoad();
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
private:
};