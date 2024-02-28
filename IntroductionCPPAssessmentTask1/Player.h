#pragma once

#include "Vec2.h"
#include "InterfaceGameObject.h"

class PlayState;

class Player :public InterfaceGameObject
{
public:
	
	PlayState* world;	
	float speed;
	float shootTimer;
	float currentTimeBeforeNextShot;

	Player();
	virtual ~Player();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
private:

};
