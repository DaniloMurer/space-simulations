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
    const SimVector3 a = {.x = 1.0, .y = 2.0, .z = 3.0};
    const SimVector3 b = {.x = 4.0, .y = 5.0, .z = 6.0};

    const SimVector3 sum = vector3_add(a, b);

    printf("Sum: (%f, %f, %f)\n", sum.x, sum.y, sum.z);

    return 0;
}