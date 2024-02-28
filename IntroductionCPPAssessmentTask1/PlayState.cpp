#include "PlayState.h"
#include "raylib.h"

//#include "Application.h"
#include "Config.h"
#include <string>
#include "Player.h"

PlayState::PlayState()
{

}

PlayState::~PlayState()
{

}

void PlayState::Load()
{
	// start the begin game background musio

	//initialise lives, health, and score
	lives = config.player.maxLives;
	health = config.player.maxHealth;
	score = 0;

	//Create initial Game Objects
	player = CreatePlayer();

}

void PlayState::UnLoad()
{
	//app->SetMusic(nullptr);

	allGameObjects.remove_if(InterfaceGameObject::Destroy);
	
}

void PlayState::Update(float deltaTime)
{
	//update all the game objects
	UpdatePlayer(deltaTime);
	

	CheckCollisions();

	allGameObjects.remove_if(InterfaceGameObject::DestroyIfDead);
}

void PlayState::Draw()
{
	DrawText("Play State", 10, 10, 24, BLACK);

	
	DrawPlayer();
	

	DrawGameUI();
}



void PlayState::DealDamage(int amount)
{
	health -= amount;
	if (health <= 0)
	{
		lives -= 1;
		health = config.player.maxHealth;

		if (lives < 0)
		{
			config.sharedGameData.score = score;
			//app->ChangeState(EGameState::GAMEOVER);
		}
		else if (lives <= 0)
		{
			
		}
		else if (lives <= 1)
		{
			
		}
	}
}

void PlayState::IncreaseScore(int amount)
{
	score += amount;
}

//Create Functions:
//-----------------------------------------------------------------
Player* PlayState::CreatePlayer()
{
	auto player = new Player();
	player->world = this;

	allGameObjects.push_back(player);

	return player;
}

//Update Functions:
//-----------------------------------------------------------------
void PlayState::UpdatePlayer(float deltaTime)
{
	player->Update(deltaTime);
}


void PlayState::CheckCollisions()
{
	for (auto iterA =allGameObjects.begin(); iterA != allGameObjects.end(); iterA++)
	{
		for (auto iterB = std::next((iterA)); iterB != allGameObjects.end(); iterB++)
		{
			InterfaceGameObject* objA = *iterA;
			InterfaceGameObject* objB = *iterB;

			float distance = (objA->position - objB->position).Length();
			float aRadius = objA->size.x / 2.0f;
			float bRadius = objB->size.x / 2.0f;

			if (distance < aRadius + bRadius)
			{
				OnCollision(objA, objB);
			}
		}
	}
}

void PlayState::OnCollision(InterfaceGameObject* objA, InterfaceGameObject* objB)
{
	
}



//Draw Functions:
//-----------------------------------------------------------------
void PlayState::DrawGameUI()
{
	float infoHeight = config.ui.infoPanelHeight;
	float maxOverlayTransparency = config.ui.maxOverlayTransparency;
	float maxHealthbarTransparency = config.ui.maxHealthbarTransparency;

	float healthPercentage = health / (float)config.player.maxHealth;
	
	//Draw Red Overlay
	if (lives <= 0)
	{
		Color redOverlayColor = { 255, 0,0,(int)(maxOverlayTransparency * 255 * (1.0f - healthPercentage)) };
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight() - infoHeight, redOverlayColor);
	}


	//Draw InfoPanel and score
	std::string strScore = std::to_string(score);
	DrawInfoPanel(strScore.c_str());

	//Draw Healthbar
	Color healthBarColor = { 255, 0, 0, (maxHealthbarTransparency * 255)};

	DrawRectangle(0, GetScreenHeight() - infoHeight +1, GetScreenWidth() * healthPercentage, 20, healthBarColor);

	//Draw Lives icon
	for (int i = 0; i < lives; i++)
	{
		/*DrawTexture(Assets::imgPlayerLifeIcon,
			10 + (i * Assets::imgPlayerLifeIcon.width),
			GetScreenHeight() - infoHeight - (Assets::imgPlayerLifeIcon.height / 2.0f),
			WHITE);*/
	}

}

void PlayState::DrawPlayer()
{
	player->Draw();
}