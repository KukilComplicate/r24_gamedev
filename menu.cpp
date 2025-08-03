
#include "menu.h"
#include <string>
#include <iostream>

using namespace std;



menu::menu()
{
    menuOption = PLAY_MENU;
    winW = GetScreenWidth();
    winH = GetScreenHeight();
    buttonData Play, Settings, Exit;
    Play.txtText = textPlay;
    buttonSize = {140 * res, 24 * res};
    menuOptionLoc = Vector2{210 * res, 50 * res};
}

void menu::DrawMenu()
{
    mLoc = GetMousePosition();
    // Menu Button
    MenuButtons();

    // Draw the Mouse
    DrawMouse();
}

// Menu Buttons
void menu::MenuButtons()
{ 

    // Draw Menu Text
    DrawText("MENU", 16 * res, 97 * res, 20 * res, BLACK);
    
    // Play Button
    Vector2 playLoc = {bLeftLoc, 130 * res};
    Color playButton = SKYBLUE;
    Color playTextCol = WHITE;

    if(CheckCollisionPointRec(mLoc, Rectangle{playLoc.x, playLoc.y, buttonSize.x, buttonSize.y}))
    {
        playButton = WHITE;
        playTextCol = DARKBLUE;
        if (IsMouseButtonPressed(0)) { cout << "Play Button Pressed!" << endl; menuOption = PLAY_MENU; }

    }

    DrawButton(playLoc, playButton);
    DrawButtonText(playLoc.y, playTextCol, textPlay);


    // Exit Button
    Vector2 exitLoc = {bLeftLoc, 165 * res};
    Color exitButton = SKYBLUE;
    Color exitTextCol = WHITE;

    if(CheckCollisionPointRec(mLoc, Rectangle{exitLoc.x, exitLoc.y, buttonSize.x, buttonSize.y}))
    {
        exitButton = WHITE;
        exitTextCol = DARKBLUE;
        if (IsMouseButtonPressed(0)) { cout << "Exit Button Pressed!" << endl; menuOption = EXIT_MENU; }
    }

    DrawButton(exitLoc, exitButton);
    DrawButtonText(exitLoc.y, exitTextCol, textExit);

}

// Draw Button for Main Menu
void menu::DrawButton(Vector2 loc, Color bgCol)
{
    DrawRectangleV(loc, buttonSize, bgCol);
}

// Draw the ButtonText
void menu::DrawButtonText(int yPos, Color col, Texture2D txt)
{
    yPos = yPos + 5 * res;
    DrawTextureEx(txt, {bLeftLoc + 10, (float)yPos}, 0.f, res, col);
}


// Draw the Mouse
void menu::DrawMouse()
{
    DrawTexture(mousetexture, GetMousePosition().x, GetMousePosition().y, WHITE);
}