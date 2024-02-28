#pragma once

#include "raylib.h"
#include <stdlib.h>

struct Config
{
	struct MinMax
	{
		float min = 0;
		float max = 1.0f;

		float RandomRange()
		{
			float val = (float)rand() / RAND_MAX;
			float range = max - min;

			return val * range + min;
		}
	};

	//------------------------------------------------
	// GAME CONFIG
	//------------------------------------------------
	struct Game
	{
		int windowWidth = 450;
		int windowHeight = 800;
		const char* windowTitle = "Space Blast";

		float bgMusicVolume = 0.1f;

		const char* highscoreFile = "Highscore.txt";
	};

	Game game;

	//------------------------------------------------
	// INPUT CONFIG:
	// Customise Keyboard Binding
	//------------------------------------------------
	struct Input
	{
		int upKey		=KEY_UP;
		int downKey		=KEY_DOWN;
		int leftKey		=KEY_LEFT;
		int rightKey	=KEY_RIGHT;
		int submitKey	=KEY_ENTER;
		int shootKey	=KEY_SPACE;
	};

	Input input;

	//------------------------------------------------
	// PLAYER CONFIG:
	// customise player health and speeds
	//------------------------------------------------
	struct Player
	{
		int maxLives = 3;
		int maxHealth = 100;
		float moveSpeed = 200;

		float bulletSpeed = 500;
		
		//in seconds
		float shootTimer = 0.1f;

		float multiplierOfShootTimer = 0.1f;
	};

	Player player;

	//------------------------------------------------
	// SPAWN CONFIG:
	// Customise speed of spawned objects
	//------------------------------------------------
	struct Spawn
	{
		//asteroid spawn variables
		MinMax asteroidXVelocityRange = { -30, 30 };
		MinMax asteroidYVelocityRange = { 150, 150 };

		MinMax asteroidSizeRange = { 75, 115 };

		MinMax asteroidSpawnFrequency = {1.0f, 3.0f};
		float asteroidSpawnTimeDecay = 0.2;

		MinMax asteroidRotationRange = { 0, 360 };
		MinMax asteroidRotationSpeedRange = { -100, 100 };


		//scared enemy spawn variables
		MinMax scaredEnemyXVelocityRange = { -30, 30 };
		MinMax scaredEnemyYVelocityRange = { 150, 150 };

		MinMax scaredEnemySizeRange = { 100, 100 };

		MinMax scaredEnemySpawnFrequency = { 1.0f, 3.0f };
		float scaredEnemySpawnTimeDecay = 0.2;

		MinMax scaredEnemyRotationRange = { 0, 360 };
		MinMax scaredEnemyRotationSpeedRange = { -100, 100 };

		//Aggresive enemy spawn variables
		MinMax aggresiveEnemyXVelocityRange = { -30, 30 };
		MinMax aggresiveEnemyYVelocityRange = { 150, 150 };

		MinMax aggresiveEnemySizeRange = { 100, 100 };

		MinMax aggresiveEnemySpawnFrequency = { 1.0f, 3.0f };
		float aggresiveEnemySpawnTimeDecay = 0.2;

		MinMax aggresiveEnemyRotationRange = { 0, 360 };
		MinMax aggresiveEnemyRotationSpeedRange = { -100, 100 };

		//Shooter enemy spawn variables		
		MinMax shooterEnemySpawnFrequency = { 1.0f, 3.0f };
		float shooterEnemySpawnTimeDecay = 0.0;

		//PowerUp spawn variables
		MinMax powerUpSizeRange = { 100, 100 };
		float chanceOfSpawning = 100.0f;

	};

	Spawn spawn;

	//------------------------------------------------
	// ENEMY CONFIG
	//------------------------------------------------
	struct Enemy
	{
		float shooterBulletSpeed = 500;
		float shooterYPos = 100;
		int shooterDamage = 5;
		int shooterScore = 500;

		float scaredRunSpeed = 300;
		int scaredDamage = 2;
		int scaredScore = 100;
		
		float aggresiveChargeSpeed = 300;
		int aggresiveDamage = 3;
		int aggresiveScore = 200;

		int asteroidDamage = 1;
		int asteroidScore = 10;

		int bulletDamage = 20;
	};

	Enemy enemy;

	//------------------------------------------------
	// UI CONFIG
	//------------------------------------------------
	struct UI
	{
		float infoPanelHeight = 80;
		float maxOverlayTransparency = 0.3f;
		float maxHealthbarTransparency = 0.5;
	};

	UI ui;

	//------------------------------------------------
	// SHARED GAME DATA
	// Readable and writable game data across different game states
	//------------------------------------------------
	struct SharedGameData
	{
		int score = 0;
	};

	SharedGameData sharedGameData;

};

extern Config config;