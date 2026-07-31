#include "physics/simulation.h"
#include "physics/newtonian_gravity.h"
#include "physics/vector3.h"

void simulate_gravity(Universe *universe, float delta_time) {
    for (int i = 0; i < universe->bodies_size; i++) {
        Body *affected_body = &universe->bodies[i];
        reset_acceleration(affected_body);
        for (int j = 0; j < universe->bodies_size; j++) {
            if (i == j) {
                continue;
            }
            const Body *affecting_body = &universe->bodies[j];

            const SimVector3 force = compute_force(affected_body, affecting_body);
            affected_body->acceleration = vector3_add(affected_body->acceleration, vector3_scale(force, 1.0 / affected_body->mass));
        }
        affected_body->temp_velocity = vector3_add(affected_body->velocity, vector3_scale(affected_body->acceleration, delta_time));
        affected_body->temp_position = vector3_add(affected_body->position, vector3_scale(affected_body->temp_velocity, delta_time));
    }

    for (int l = 0; l < universe->bodies_size; l++) {
        Body *body = &universe->bodies[l];
        integrate_position(body);
        integrate_velocity(body);
    }
}


SimVector3 compute_force(const Body *affected_body, const Body *affecting_body) {
    const SimVector3 direction = vector3_subtract(affecting_body->position, affected_body->position);

    const double distance = vector3_magnitude(direction);

    const SimVector3 normalized_direction = vector3_normalize(direction, distance);

    const double force_scalar = newtonian_gravity_force(affecting_body->mass, affected_body->mass, distance);

    const SimVector3 force = vector3_scale(normalized_direction, force_scalar);

    return force;
}

Body create_body(
    const int mass,
    const double vx,
    const double vy,
    const double vz,
    const double px,
    const double py,
    const double pz,
    const Color color,
    const float radius
    ) {
    Body body;
    body.mass = mass;
    body.velocity = (SimVector3) {.x = vx, .y = vy, .z = vz};
    body.position = (SimVector3) {.x = px, .y = py, .z = pz};
    body.color = color;
    body.radius = radius;
    body.acceleration = (SimVector3) {.x = 0, .y = 0, .z = 0};
    body.temp_velocity = (SimVector3) {.x = 0, .y = 0, .z = 0};
    body.temp_position = (SimVector3) {.x = 0, .y = 0, .z = 0};
    return body;
}

void reset_acceleration(Body *body) {
    body->acceleration = (SimVector3) {.x = 0, .y = 0, .z = 0};
}

void integrate_position(Body *body) {
    body->position = body->temp_position;
    body->temp_position = (SimVector3) { .x = 0, .y = 0, .z = 0};
}

void integrate_velocity(Body *body) {
    body->velocity = body->temp_velocity;
    body->temp_velocity = (SimVector3) { .x = 0, .y = 0, .z = 0};
}