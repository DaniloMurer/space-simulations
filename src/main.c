#include <math.h>
#include <stdlib.h>
#include <raylib.h>
#include <stdio.h>
#include <physics/vector3.h>
#include <physics/simulation.h>
#include <engine/engine.h>

int main(void)
{
    InitWindow(900, 700, "Space Simulation");
    SetTargetFPS(60);
    Universe *universe = malloc(sizeof(Universe));
    // earth
    universe->bodies[0] = (Body) {
        .mass = 15, .position = (SimVector3){.x = 500, .y = 400, .z = 0}, .velocity = (SimVector3){.x = 0, .y = 0, .z = 0}
    };
    // moon
    universe->bodies[1] = (Body) {
        .mass = 2, .position = (SimVector3){.x = 800, .y = 0, .z = 0}, .velocity = (SimVector3){.x = 0, .y = 40, .z = 0}
    };

    double accumulator = 0.0;
    // we update approximately every 16ms or every 60 frames
    const float physics_dt = 0.016f;
    const float accelerate_time = 1.0f;

    Camera2D camera = {0};
    camera.target = (Vector2) {
        .x = 500,
        .y = 400
    };
    camera.offset = (Vector2) {
        .x = 450,
        .y = 350
    };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {

        camera.zoom = expf(logf(camera.zoom) + GetMouseWheelMove() * 0.1f);
        accumulator += GetFrameTime();
        while (accumulator >= physics_dt)
        {
            simulate_earth_moon_system(universe, physics_dt * accelerate_time);
            accumulator -= physics_dt;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(20, 20);
        BeginMode2D(camera);
        // Your code here
        render(universe);
        EndMode2D();
        EndDrawing();
    }

    free(universe);
    CloseWindow();
    return 0;
}