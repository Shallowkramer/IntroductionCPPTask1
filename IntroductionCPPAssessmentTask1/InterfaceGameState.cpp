#include "InterfaceGameState.h"
#include "Config.h"
#include "raylib.h"

InterfaceGameState::InterfaceGameState()
{
	
}

 InterfaceGameState::~InterfaceGameState()
{

}

 void InterfaceGameState::Load()
{

}

 void InterfaceGameState::UnLoad()
{

}

 void InterfaceGameState::Update(float deltaTime)
{

}

 void InterfaceGameState::Draw()
{

}

 void InterfaceGameState::DrawTitleText()
 {
	
 }

 void InterfaceGameState::DrawSubTitleText(const char* text)
 {
	 
 }

 void InterfaceGameState::DrawInfoPanel(const char* infoText)
 {
	 float infoHeight = config.ui.infoPanelHeight;

	 //Draw Rectangle
	 DrawRectangle(0, GetScreenHeight() - infoHeight, GetScreenWidth(), infoHeight, { 0,0,0,128 });

	 //Draw Line
	 DrawLine(0, GetScreenHeight() - infoHeight, GetScreenWidth(), GetScreenHeight() - infoHeight, WHITE);

	 //Draw Text
	 auto ts = MeasureText(infoText, 32);
	 DrawText(infoText, ( GetScreenWidth() / 2.0f - ts / 2.0f), (GetScreenHeight() - infoHeight + 25 ), 32, WHITE);
 }