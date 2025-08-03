#include "raylib.h"

class Collectibles{
public:
    Collectibles(int w, int h, Vector2 Pos);
    void Render(Vector2 characterPos, float deltaTime);
    Rectangle Collision(Vector2 characterPos);
    void Collected();
    bool isAvail();
private:
    //
    Texture2D texture = LoadTexture("textures/collectibles/coins.png");
    float tWidth{};
    float tHeight{};
    Vector2 worldPos{};

    // anim data
    int frame{};
    int maxFrame{};
    float runningTime{};
    float dTime{};
    float updateTime{1.f/12.f};
    float Scale{3.0};
    
    // game data
    bool isAvailable{true};
};