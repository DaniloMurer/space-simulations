#include <raylib.h>
#include <engine/engine.h>

void render(const Universe *universe) {
    for (int i = 0; i < universe->bodies_size; i++) {
        const Body body = universe->bodies[i];
        DrawCircle((int) body.position.x, (int) body.position.y, body.radius, body.color);
        const int start = body.positions_count < MAX_POSITIONS ? 0 : body.positions_index;
        for (int j = 0; j < body.positions_count - 1; j++) {
            const int current = (start + j) % MAX_POSITIONS;
            const int next = (start + j + 1) % MAX_POSITIONS;

            const Vector2 start_position = (Vector2) { .x = (float) body.positions[current].x, .y = (float) body.positions[current].y };
            const Vector2 end_position = (Vector2) { .x = (float) body.positions[next].x, .y = (float) body.positions[next].y };

            DrawLineV(
                start_position,
                end_position,
                body.color
            );
        }
    }
}