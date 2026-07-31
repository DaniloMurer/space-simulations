#include <raylib.h>
#include <engine/engine.h>

void render(const Universe *universe) {
    for (int i = 0; i < universe->bodies_size; i++) {
        const Body body = universe->bodies[i];
        DrawCircle((int) body.position.x, (int) body.position.y, body.radius, body.color);
    }
}