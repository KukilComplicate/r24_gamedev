#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "raymath.h"

class character
{
public:
    character();
    ~character();
    void tick();
    Vector2 getWorldLoc() { return worldLoc; }
    void undoMovement();
    Rectangle collisionRec();
    int getHealth();
    int Number(); // for testing
private:
    Vector2 worldLoc{};
    Vector2 worldLastLoc{};
    Vector2 ScreenLoc{};
    float speed{4.0f};

    float health{54.f};
    const float maxhealth{100};
    int num;

    // frame data
    int frame{0};
    int maxFrame{8};
    float time;
    int framePos{0};
    float updateTime{1.0f/12.0f};
    float textureWidth;
    float textureHeight;
    float scale{3.0f};

    // Collision Data
    Rectangle colRec;
    
    // texutres
    Texture2D texture = LoadTexture("textures/character/idle.png");
    Texture2D idle = LoadTexture("textures/character/idle.png");
    Texture2D walk = LoadTexture("textures/character/walk.png");
    Texture2D run = LoadTexture("textures/character/run.png");
};

#endif