
#include "gamehud.h"


gamehud::gamehud()
{
    winH = GetScreenHeight();
    winW = GetScreenWidth();
    cout << "Game HUD Created!" << endl;
}
void gamehud::Tick()
{
    mLoc = GetMousePosition();
    // Draw Inventory based
    inventory ? DrawInventory(): DrawHUD();
    
    if(IsKeyPressed(KEY_I)) inventory = !inventory;
    if(IsKeyPressed(KEY_K)) Damage(20);
    if(IsKeyPressed(KEY_H)) Damage(-20);

    // player health
    if(playerHealth <= 0)  playerHealth = 0;
    if (playerHealth > maxHealth) playerHealth = maxHealth;

}
void gamehud::DrawHUD()
{
    Rectangle health{10, 10, 100, 10};
    DrawRectangle(health.x, health.y, maxHealth, health.height, GRAY);
    DrawRectangle(health.x, health.y, playerHealth, health.height, GREEN);
}
void gamehud::DrawInventory()
{
    // Draw the Inventory
    
    for(int i = -1; i <= 1; i++)
    {
        DrawRectangle( (winW/2) + (i * 75) - 25, winH/2 - 25, 50*res, 50*res, ColorAlpha(GRAY, 0.7f));
    }
    
    DrawText(TextFormat("%d", getHealth()), 10, 10, 30, BLACK);
    DrawMouse();
}
/*void gamehud::DrawMouse()
{
    DrawTexture(mousetexture, mLoc.x, mLoc.y, WHITE);
}*/

void gamehud::Damage(float damage)
{
    playerHealth = playerHealth - damage;
}
