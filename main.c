#include <raylib.h>

int main(void)
{
    InitWindow(800, 600, "Space Simulation");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // Your code here
        EndDrawing();
    }

    CloseWindow();
    return 0;
}