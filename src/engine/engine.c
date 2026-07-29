#include <raylib.h>
#include <engine/engine.h>

void render(Universe *universe) {
    // render earth
    DrawCircle((int) universe->bodies[0].position.x, (int) universe->bodies[0].position.y, 20.0f, BLUE);

    // render moon
    DrawCircle((int) universe->bodies[1].position.x, (int) universe->bodies[1].position.y, 10.0f, WHITE);
}