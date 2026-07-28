#include <physics/vector3.h>
#include <stdlib.h>
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

int main(void) {
    Universe *universe = malloc(sizeof(Universe));
    // earth
    universe->bodies[0] = (Body) {
        .mass = 150, .position = (SimVector3){.x = 0, .y = 0, .z = 0}, .velocity = (SimVector3){.x = 0, .y = 0, .z = 0}
    };
    // moon
    universe->bodies[1] = (Body) {
        .mass = 50, .position = (SimVector3){.x = 500, .y = 0, .z = 0}, .velocity = (SimVector3){.x = 0, .y = 200, .z = 0}
    };
    simulate_earth_moon_system(universe);

    free(universe);

    return 0;
}