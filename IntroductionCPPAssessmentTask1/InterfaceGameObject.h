#pragma once

#include "Vec2.h"

enum class GameObjectTypes
{
	UNDEFINED,
	PLAYER,
};

class InterfaceGameObject
{
public:

	GameObjectTypes type = GameObjectTypes::UNDEFINED;

	Vec2 position;
	Vec2 size;
	float rotation;
	Vec2 velocity;

	bool isAlive;

	InterfaceGameObject();
	virtual ~InterfaceGameObject();

	virtual void Update(float deltaTime);
	virtual void Draw();

	static bool IsDead(InterfaceGameObject* obj);
	static bool Destroy(InterfaceGameObject* obj);
	static bool DestroyIfDead(InterfaceGameObject* obj);

private:

};

