#include "InterfaceGameObject.h"

InterfaceGameObject::InterfaceGameObject()
{
	isAlive = true;
	rotation = 0.0f;
}

InterfaceGameObject::~InterfaceGameObject()
{

}

void InterfaceGameObject::Update(float deltaTime)
{

}

void InterfaceGameObject::Draw()
{

}

bool InterfaceGameObject::IsDead(InterfaceGameObject* obj)
{
	return !obj->isAlive;
}
bool InterfaceGameObject::Destroy(InterfaceGameObject* obj)
{
	delete obj;
	return true;
}
bool InterfaceGameObject::DestroyIfDead(InterfaceGameObject* obj)
{
	if (!obj->isAlive)
	{
		delete obj;
		return true;
	}

	return false;
}