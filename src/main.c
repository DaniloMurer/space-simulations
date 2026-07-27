#include <raylib.h>
#include <physics/vector3.h>
#include <stdio.h>

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
    SimVector3 a = {1.0f, 2.0f, 3.0f};
    SimVector3 b = {4.0f, 5.0f, 6.0f};

    SimVector3 sum = vector3_add(a, b);

    printf("Sum: (%f, %f, %f)\n", sum.x, sum.y, sum.z);

    return 0;
}