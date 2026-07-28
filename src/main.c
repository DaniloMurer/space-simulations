#include <raylib.h>
#include <physics/vector3.h>
#include <stdio.h>
#include <physics/simulation.h>

/*int main(void)
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
}*/

int main(void)
{
    simulate_earth_moon_system();

    return 0;
}