#include <math.h>
#include <stdlib.h>
#include <raylib.h>
#include <time.h>
#include <physics/simulation.h>
#include <engine/engine.h>

double random_double() {
    int min = 3000;
    int max = 10000;
    return min + ((double)rand() / (double)RAND_MAX) * (max - min);
}

double random_velocity() {
    int min = 50;
    int max = 300;
    return min + ((double)rand() / (double)RAND_MAX) * (max - min);
}



int random_mass() {
    int min = 30;
    int max = 60000;
    return min + (rand() / (double)RAND_MAX) * (max - min);
}

float random_float() {
    int min = 10.0f;
    int max = 60.0f;
    return min + ((float)rand() / (double)RAND_MAX) * (max - min);
}

int main(void)
{
    const int bodies = 500;
    srand((unsigned int)time(NULL));
    Color color[20] = {RED, GREEN, BLUE, YELLOW, PURPLE, WHITE, GREEN, DARKBLUE, WHITE, GREEN, BLUE, YELLOW, PURPLE, WHITE, GREEN, DARKBLUE, WHITE, GREEN, BLUE, YELLOW};
    InitWindow(900, 700, "Space Simulation");
    SetTargetFPS(60);
    Universe *universe = malloc(sizeof(Universe));
    // planet
    for (int i = 0; i < bodies; i++) {
        universe->bodies[i] = create_body(random_mass(), random_velocity(), random_velocity(), 0.0, random_double(), random_double(), random_double(), color[i % 20], random_float());
    }
    /*universe->bodies[0] = create_body(1000, 0, 220, 0, 4500, 0, 0, BLUE, 50.0f);
    // moons
    universe->bodies[1] = create_body(10, 0, 320, 0, 4900, 0, 0, WHITE, 40.0f);
    universe->bodies[2] = create_body(15, 0, 290, 0, 5300, 0, 0, GREEN, 45.0f);
    // star
    universe->bodies[3] = create_body(50000, 0, 0, 0, 500, 400, 0, RED, 80.0f);*/

    universe->bodies_size = bodies;

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