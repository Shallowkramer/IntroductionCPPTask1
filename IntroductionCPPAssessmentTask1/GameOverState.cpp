#include "GameOverState.h"
#include "raylib.h"

#include "Application.h"
#include "Config.h"
#include "MyString.h"

GameOverState::GameOverState()
{

}

GameOverState::~GameOverState()
{

}

void GameOverState::Load()
{
	
}

void GameOverState::UnLoad()
{
	app->SetMusic(nullptr);
}

void GameOverState::Update(float deltaTime)
{
	for (char c = 'A'; c <= 'Z'; c++)
	{
		if (IsKeyPressed(c))
		{
			name += c;
		}
	}

	if (IsKeyPressed(KEY_BACKSPACE)&& name.empty() == false)
	{
		name.pop_back();
	}

	if (IsKeyPressed(KEY_ENTER) && name.empty() == false) 
	{
		
	}
}

void GameOverState::Draw()
{
	Color redOverlayColor = { 255, 0,0,(int)(config.ui.maxOverlayTransparency * 255 ) };

	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight() - config.ui.infoPanelHeight - 1, redOverlayColor);

	DrawTitleText();
	DrawSubTitleText("Gameover");

	/*std::string scoreText = std::to_string(config.sharedGameData.score);
	auto ts = MeasureTextEx(Assets::fntKenVectorThin, scoreText.c_str(), 32, 0);
	DrawTextEx(Assets::fntKenVectorThin, scoreText.c_str(), { GetScreenWidth() / 2.0f - ts.x/2.0f, 200.0f }, 32, 0, WHITE);

	std::string enterYourNameText = "Enter your name";
	ts = MeasureTextEx(Assets::fntKenVector, enterYourNameText.c_str(), 32, 0);
	DrawTextEx(Assets::fntKenVector, enterYourNameText.c_str(), { GetScreenWidth() / 2.0f - ts.x / 2.0f, 300.0f }, 32, 0, WHITE);

	ts = MeasureTextEx(Assets::fntKenVectorThin, name.c_str(), 32, 0);
	DrawTextEx(Assets::fntKenVectorThin, name.c_str(), { GetScreenWidth() / 2.0f - ts.x / 2.0f, 340.0f }, 32, 0, WHITE);

	std::string enterToContinueText = "";
	if (name.empty() == false)
	{
		enterToContinueText = "Enter to continue";
	}
	DrawInfoPanel(enterToContinueText.c_str());*/
}