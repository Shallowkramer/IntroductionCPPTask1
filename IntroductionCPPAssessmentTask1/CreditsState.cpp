#include "CreditsState.h"
#include "raylib.h"

#include "Application.h"
#include <vector>
#include "MyString.h"
#include "Config.h"

CreditsState::CreditsState()
{

}

CreditsState::~CreditsState()
{

}

void CreditsState::Load()
{
	
}

void CreditsState::UnLoad()
{
	
}

void CreditsState::Update(float deltaTime)
{
	if (IsKeyPressed(config.input.submitKey))
	{
		app->ChangeState(EGameState::MENU);
	}
}

void CreditsState::Draw()
{
	DrawText("Credits State", 10, 10, 24, BLACK);

	DrawTitleText();
	DrawSubTitleText("Credits");

	MyString strings[3];

	strings[0] = "Mark Richards";
	strings[1] = "Developed at AIE Adelaide Campus";
	strings[2] = "08/03/2024";


	for (int i=0; i < 3; i++)
	{
		int ts = MeasureText(strings[i].CStr(), 24);
		
		DrawText(strings[i].CStr(), 
			(GetScreenWidth() / 2.0f) - (ts / 2.0f ), 
			(200.0f + (i * 24)), 
			24,
			WHITE
		);
	}

	DrawInfoPanel("Enter to Continue");

}