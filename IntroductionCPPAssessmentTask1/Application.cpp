#include "Application.h"
#include <iostream>
#include "raylib.h"
#include "config.h"
#include "MenuState.h"
#include "CreditsState.h"
#include "PlayState.h"
#include "GameOverState.h"

Application:: Application()
{

}
Application::~Application()
{

}

void Application::Run()
{
    std::cout << config.game.windowWidth << std::endl;
    std::cout << config.game.windowHeight << std::endl;
    
    

    InitWindow(config.game.windowWidth, config.game.windowHeight, config.game.windowTitle);
    InitAudioDevice();


    SetTargetFPS(60);


    ChangeState(EGameState::MENU);

    float bgXOffSet = 0.0f;
    float bgYOffSet = 0.0f;

    while (!WindowShouldClose() && shouldExit == false)
    {
        // Update
        //----------------------------------------------------------------------------------

        ChangeToNextState();

        float deltaTime = GetFrameTime();

        UpdateMusic(deltaTime);


        //scroll the background texture
        bgYOffSet -= 1;

        if (IsKeyPressed(KEY_ONE))
        {
            ChangeState(EGameState::MENU);
        }

        if (IsKeyPressed(KEY_TWO))
        {
            ChangeState(EGameState::PLAY);
        }

        if (IsKeyPressed(KEY_THREE))
        {
            ChangeState(EGameState::GAMEOVER);
        }

        if (IsKeyPressed(KEY_FOUR))
        {
            ChangeState(EGameState::HIGHSCORE);
        }

        if (IsKeyPressed(KEY_FIVE))
        {
            ChangeState(EGameState::CREDITS);
        }


        currentGameState->Update(deltaTime);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //draw background Texture
        /*DrawTexturePro(
            Assets::imgBackground,
            { bgXOffSet, bgYOffSet, (float)GetScreenWidth(), (float)GetScreenHeight() },
            { 0,0, (float)GetScreenWidth(), (float)GetScreenHeight() },
            { 0,0 },
            0.0f,
            WHITE
            );*/

        currentGameState->Draw();

        EndDrawing();
    }
    currentGameState->UnLoad();

    CloseAudioDevice();
    CloseWindow();

}

void Application::ChangeToNextState()
{
    if (nextState == EGameState::NONE)
    {
        return;
    }
    if (currentGameState != nullptr)
    {
        currentGameState->UnLoad();
        delete currentGameState;
    }
       

    switch (nextState)
    {
    case EGameState::MENU: currentGameState = new MenuState();
    {
        break;
    }
    case EGameState::PLAY: currentGameState = new PlayState();
    {
        break;
    }
    case EGameState::GAMEOVER: currentGameState = new GameOverState();
    {
        break;
    }
    case EGameState::CREDITS: currentGameState = new CreditsState();
    {
        break;
    }
    }
    currentGameState->app = this;
    currentGameState->Load();

    
    nextState = EGameState::NONE;
}

void Application::ChangeState(EGameState newState)
{
    nextState = newState;
}

void Application::UpdateMusic(float deltaTime)
{
    
    if (nextMusic!=currentMusic)
    {
        musicVolume -= deltaTime;
        if (musicVolume <= 0.0f)
        {
            if (currentMusic != nullptr)
            {
                StopMusicStream(*currentMusic);
            }

            currentMusic = nextMusic;

            if (currentMusic!= nullptr)
            {
                PlayMusicStream(*currentMusic);
            }
        }
    }
    else
    {
        musicVolume += deltaTime;
        if (musicVolume > 1.0f)
        {
            musicVolume = 1.0f;
        }
    }
    
    if (currentMusic != nullptr)
    {
        SetMusicVolume(*currentMusic, musicVolume*config.game.bgMusicVolume);
        UpdateMusicStream(*currentMusic);
    }
    
}

void Application::SetMusic(Music* newMusic)
{
    nextMusic = newMusic;
}

void Application::Quit()
{
    shouldExit = true;
}
