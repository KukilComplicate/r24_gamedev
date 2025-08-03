#include <string>
#include <iostream>


#include "raylib.h"

using namespace std;

// custon files
#include "character.h"
#include "collectibles.h"
#include "menu.h"
#include "gamehud.h"

// res data
int winW = 480, winH = 270;
int res = 1;

// GameStatus
enum gamestatus{
    LOADING,
    MENU,
    PLAY
};

gamestatus GameStat = LOADING;
gamestatus GameStatDef = LOADING;


int main()
{
    cout << "Raylib Version: " << RAYLIB_VERSION << endl;

     InitWindow(winW*res, winH*res, "GameDev 19");
    SetExitKey(KEY_BACKSPACE);

    // 
    character Player;
    Collectibles coins(winW, winH, {100, 100});
    menu MenuUI;
    gamehud GameHUD;

    // map
    Texture2D map = LoadTexture("textures/map/map1.png");
    Vector2 mapLoc{};
    float mapScale{2.0f};

    // FPS Limit
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        // float deltaTime = GetFrameTime();
    
        // Begins Draw
        BeginDrawing();
        ClearBackground(WHITE);

        if(IsKeyPressed(KEY_P))
        {
            GameStat = PLAY;  
        }
        
        if(GameStat == PLAY)
        {
            mapLoc = Vector2Scale(Player.getWorldLoc(), -1); 
            // Draw the map
            DrawTextureEx(map, mapLoc, 0, mapScale, WHITE);

            
            HideCursor();

            Player.tick();
            coins.Render({}, GetFrameTime());
            GameHUD.Tick();
            if ( Player.getWorldLoc().x < 0 ||
                 Player.getWorldLoc().y < 0 ||
                 Player.getWorldLoc().x + winW > map.width*mapScale ||
                 Player.getWorldLoc().y + winH > map.height*mapScale
                )
            {
                Player.undoMovement();
            }
        }
        else
        {
            
            HideCursor();
            MenuUI.DrawMenu();
        }

        // Ends Draw
        EndDrawing();
    }
    // Closes the Window
    CloseWindow();
    
    
    return 0;
}