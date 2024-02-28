#include "Player.h"
#include "raylib.h"
#include "Config.h"
#include "PlayState.h"

Player::Player() : InterfaceGameObject()
{
	type = GameObjectTypes::PLAYER;

	world = nullptr;

	position.x = GetScreenWidth() / 2.0f;
	position.y = GetScreenHeight() - 150.0f;

	size.x = 0;
	size.y = 0;

	speed = config.player.moveSpeed;

	shootTimer = config.player.shootTimer;

	currentTimeBeforeNextShot = 0.0f;
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	
}

void Player::Draw()
{
	
}

