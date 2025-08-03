#include "raylib.h"

class object
{
public:
    object();
    ~object();
private:
    Vector2 worldLoc;
    Texture2D texture = LoadTexture("");
};