#ifndef MENU_H
#define MENU_H

#include <string>
#include "raylib.h"
#include "raymath.h"

enum EMenu
{
    PLAY_MENU,
    SETTINGS_MENU,
    EXIT_MENU
};

struct buttonData
{
    int xLoc{};
    int yPos{160};
    Texture2D txtText;
};

class menu
{
public:
    menu();
    void DrawMenu();
    void MenuButtons();
    void DrawButton(Vector2 loc, Color bgCol);
    void DrawButtonText(int yPos, Color col, Texture2D txt);
    void DrawMouse();

private:
    EMenu menuOption;
    // win Data
    int winW;
    int winH;
    float res{1.0f};
    float bLeftLoc{30};
    Vector2 mLoc;
    Vector2 buttonSize;

    // Menu Option Data
    Vector2 menuOptionLoc{208*res,16*res};


    // textures from ui
    Texture2D button = LoadTexture("ui/menu_txtButton.png");
    Texture2D textPlay = LoadTexture("ui/textPlay.png");

    Texture2D textExit = LoadTexture("ui/textExit.png");
    Texture2D mousetexture = LoadTexture("ui/mouse.png");
    Texture2D txtMenuOptions = LoadTexture("ui/menu_options.png");
    
};

#endif