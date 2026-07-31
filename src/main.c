#include <math.h>
#include <stdlib.h>
#include <raylib.h>
#include <physics/simulation.h>
#include <engine/engine.h>

int main(void)
{
    InitWindow(900, 700, "Space Simulation");
    SetTargetFPS(60);
    Universe *universe = malloc(sizeof(Universe));
    // planet
    universe->bodies[0] = create_body(1000, 0, 220, 0, 4500, 0, 0, BLUE, 50.0f);
    // moons
    universe->bodies[1] = create_body(10, 0, 320, 0, 4900, 0, 0, WHITE, 40.0f);
    universe->bodies[2] = create_body(15, 0, 290, 0, 5300, 0, 0, GREEN, 45.0f);
    // star
    universe->bodies[3] = create_body(50000, 0, 0, 0, 500, 400, 0, RED, 80.0f);

    universe->bodies_size = 4;

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
            simulate_gravity(universe, physics_dt * accelerate_time);
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