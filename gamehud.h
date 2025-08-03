#ifndef GAMEHUD_H
#define GAMEHUD_H

#include "raylib.h"
#include "menu.h"
#include "character.h"

#include <iostream>
using namespace std;

class gamehud: public menu, character
{
public:
    gamehud();
    void Tick();
    void DrawHUD();
    void DrawInventory();
    //void DrawMouse();
    void Damage(float damage);
    float res{1};
private:
    // main data
    bool inventory = false;
    Vector2 mLoc{};
    // HUD Data
    float playerHealth{100};
    float maxHealth{150};
    int Level;
    int Coins;
    
    // Inventory Data

    // window size
    int winH;
    int winW;
    
    // textures
    Texture2D mousetexture = LoadTexture("ui/mouse.png");
};

#endif