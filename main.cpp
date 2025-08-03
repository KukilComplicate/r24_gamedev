#include <stdio.h>

#include "raylib.h"

int main()
{
  printf("Hello!\n");
  InitWindow(480, 270, "Hello!");
  while(!WindowShouldClose())
  {
    ClearBackground(RAYWHITE);
    BeginDrawing();
    DrawFPS(10, 10);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

