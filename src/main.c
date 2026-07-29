#include <stdlib.h>
#include <raylib.h>
#include <physics/vector3.h>
#include <physics/simulation.h>
#include <engine/engine.h>

int main(void)
{
    InitWindow(900, 700, "Space Simulation");
    SetTargetFPS(120);
    Universe *universe = malloc(sizeof(Universe));
    // earth
    universe->bodies[0] = (Body) {
        .mass = 15, .position = (SimVector3){.x = 500, .y = 400, .z = 0}, .velocity = (SimVector3){.x = 0, .y = 0, .z = 0}
    };
    // moon
    universe->bodies[1] = (Body) {
        .mass = 2, .position = (SimVector3){.x = 800, .y = 0, .z = 0}, .velocity = (SimVector3){.x = 0, .y = 20, .z = 0}
    };

    /*// whatever this is
    universe->bodies[2] = (Body) {
        .mass = 1000, .position = (SimVector3){.x = 200, .y = 100, .z = 0}, .velocity = (SimVector3){.x = 0, .y = 0, .z = 0}
    };*/

    double accumulator = 0.0;
    // we update approximately every 16ms or every 60 frames
    const float physics_dt = 0.016f;
    const float accelerate_time = 1.0f;

    while (!WindowShouldClose())
    {
        accumulator += GetFrameTime();
        while (accumulator >= physics_dt)
        {
            simulate_earth_moon_system(universe, physics_dt * accelerate_time);
            accumulator -= physics_dt;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(20, 20);
        // Your code here
        render(universe);
        EndDrawing();
    }

    free(universe);
    CloseWindow();
    return 0;
}