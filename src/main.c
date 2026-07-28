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

static Body *create_body(float mass, SimVector3 position, SimVector3 velocity)
{
    Body *body = malloc(sizeof(Body));
    body->mass = mass;
    body->position = position;
    body->velocity = velocity;
    return body;
}

int main(void)
{
    Universe *universe = malloc(sizeof(Universe));
    // earth
    universe->bodies[0] = create_body(150, (SimVector3){.x = 0, .y = 0, .z = 0}, (SimVector3){.x = 0, .y = 0, .z = 0});
    // moon
    universe->bodies[1] = create_body(50, (SimVector3){.x = 500, .y = 0, .z = 0}, (SimVector3){.x = 0, .y = 200, .z = 0});
    simulate_earth_moon_system(universe);

    free(universe->bodies[0]);
    free(universe->bodies[1]);
    free(universe);

    return 0;
}