#include "Collectibles.h"
#include "raylib.h"
#include "raymath.h"

Collectibles::Collectibles(int sWidth, int sHeight, Vector2 pos)
{
    maxFrame = 14;
    tWidth = texture.width/14;
    tHeight = texture.height;
    worldPos = pos;

}
void Collectibles::Render(Vector2 charPos, float deltaTime)
{
    dTime = deltaTime;
    runningTime = runningTime + dTime;
    if (runningTime >= updateTime)
    {
        runningTime = 0;
        frame = frame + 1;
        if (frame > maxFrame/2) frame = 0;
    }
    
    Vector2 screenPos = Vector2Subtract(worldPos, charPos);


    Rectangle source = Rectangle{frame * tWidth, 0.f, tWidth, tHeight};
    Rectangle dest = Rectangle{screenPos.x, screenPos.y, Scale*tWidth, Scale*tHeight};
    DrawTexturePro(texture, source, dest, {}, 0, WHITE);
    DrawRectangle(screenPos.x, screenPos.y, Scale*tWidth, Scale*tHeight, ColorAlpha(GREEN, 0.3));
}

Rectangle Collectibles::Collision(Vector2 charPos)
{
    Vector2 screenPos{Vector2Subtract(worldPos, charPos)};
    return Rectangle{
        screenPos.x,
        screenPos.y,
        Scale*tWidth,
        Scale*tHeight
    };
}

void Collectibles::Collected()
{
    isAvailable = false;
}

bool Collectibles::isAvail()
{
    return isAvailable;
}
