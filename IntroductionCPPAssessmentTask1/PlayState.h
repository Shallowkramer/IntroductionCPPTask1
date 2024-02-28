#pragma once

#include "InterfaceGameState.h"
#include <list>

class Player;
class InterfaceGameObject;

class PlayState : public InterfaceGameState
{
public:
	PlayState();
	virtual ~PlayState();

	virtual void Load();
	virtual void UnLoad();
	virtual void Update(float deltaTime);

	void UpdatePlayer(float deltaTime);

	void CheckCollisions();
	void OnCollision(InterfaceGameObject* objA, InterfaceGameObject* objB);


	virtual void Draw();

	void DrawGameUI();
	void DrawPlayer();

	void DealDamage(int amount);
	void IncreaseScore(int amount);

	Player* CreatePlayer();

protected:
private:

	int lives;
	int health;
	int score;

	Player *player;

	std::list<InterfaceGameObject*> allGameObjects;


	
};