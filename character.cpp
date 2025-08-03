#include "character.h"

character::character()
{
    num = 10; // for testing


    
    textureHeight = texture.height/4;
    textureWidth = texture.width/maxFrame;
    colRec.width = (textureWidth*scale/2) - (1*scale);
    colRec.height = textureHeight*scale/2;

    // Set Screen Location
    ScreenLoc.y = GetScreenHeight()/2 - textureHeight/2;
    ScreenLoc.x = GetScreenWidth()/2 - textureWidth/2;
}

character::~character()
{
}

void character::tick()
{
    worldLastLoc = worldLoc;

    // moveDir move direction
    Vector2 moveDir{0};
    if(IsKeyDown(KEY_A)) { moveDir.x = -1; framePos = 3; }
    if(IsKeyDown(KEY_D)) { moveDir.x = 1; framePos = 1; }
    if(IsKeyDown(KEY_W)) { moveDir.y = -1; framePos = 2; }
    if(IsKeyDown(KEY_S)) { moveDir.y = +1; framePos = 0; }

    if(Vector2Length(moveDir) != 0)
    {
        texture = walk;
    }
    else
    {
        texture = idle;
    }

    worldLoc = Vector2Add(worldLoc, Vector2Scale(Vector2Normalize(moveDir), speed));
    
    time = time + GetFrameTime(); 
    if(time >= updateTime) {
        frame++;
        time = 0;
        if(frame > maxFrame)
        {
            frame = 0;
        }
    }
    
    
    Rectangle Src{frame*textureWidth, framePos*textureHeight, textureWidth, textureHeight};
    Rectangle Dest{ScreenLoc.x, ScreenLoc.y, textureWidth*scale, textureHeight*scale};
    DrawTexturePro(texture, Src, Dest, {}, 0.f, WHITE);

    // Collision
    colRec.x = Dest.x + 8.2f*scale;
    colRec.y = Dest.y + 8.0f*scale;
    

    // Prints the Data
    DrawText(TextFormat("WorldLoc: %.2f %.2f", worldLoc.x, worldLoc.y), 10, 220, 20, BLACK);
    DrawText(TextFormat("Health: %.2f", health), 10, 240, 20, DARKGREEN);
    DrawRectangleRec(collisionRec(), ColorAlpha(RED, .5));
}

void character::undoMovement()
{
    worldLoc = worldLastLoc;
}

Rectangle character::collisionRec()
{
    return colRec;
}

int character::getHealth()
{
    return health;
}

// for testing the funciton
int character::Number()
{
    return num;
}

