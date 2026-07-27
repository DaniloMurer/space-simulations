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
    SimVector3 a = {1.0, 2.0, 3.0};
    SimVector3 b = {4.0, 5.0, 6.0};

    SimVector3 sum = vector3_add(a, b);

    printf("Sum: (%f, %f, %f)\n", sum.x, sum.y, sum.z);

    return 0;
}