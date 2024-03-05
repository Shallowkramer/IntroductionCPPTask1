#pragma once

class Application;

enum class EGameState
{
	NONE,
	MENU,
	PLAY,
	GAMEOVER,
	CREDITS
};

class InterfaceGameState
{
public:
	InterfaceGameState();
	virtual ~InterfaceGameState();

	virtual void Load();
	virtual void UnLoad();
	virtual void Update(float deltaTime);
	virtual void Draw();

	Application* app = nullptr;

	void DrawTitleText();
	void DrawSubTitleText(const char* text);
	void DrawInfoPanel(const char* infoText);

protected:
private:
};