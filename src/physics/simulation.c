#include "physics/simulation.h"
#include "physics/newtonian_gravity.h"
#include "physics/vector3.h"
#include <stdio.h>

static Body earth = {
    .position = {.x = 150, .y = 0.0, .z = 0.0},
    .velocity = {.x = 0.0, .y = 0.0, .z = 0.0},
    .mass = 200.0,
};

static Body moon = {
    .position = {.x = 500, .y = 0.0, .z = 0.0},
    .velocity = {.x = 0.0, .y = 80.0, .z = 0.0},
    .mass = 50.0,
};

void simulate_earth_moon_system()
{
    printf("Moon position: (%f, %f, %f)\n", moon.position.x, moon.position.y, moon.position.z);

    const double delta_time = 0.016;
    for (int i = 0; i < 100; i++) {
        const SimVector3 direction = vector3_subtract(earth.position, moon.position);

        const double distance = vector3_magnitude(direction);

        const SimVector3 normalized_direction = vector3_normalize(direction, distance);

        const double force_scalar = newtonian_gravity_force(earth.mass, moon.mass, distance);

        const SimVector3 force = vector3_scale(normalized_direction, force_scalar);

        printf("Force: (%f, %f, %f)\n", force.x, force.y, force.z);

        const SimVector3 moon_acceleration = vector3_scale(force, 1.0 / moon.mass);

        moon.velocity = vector3_add(moon.velocity, vector3_scale(moon_acceleration, delta_time));

        moon.position = vector3_add(moon.position, vector3_scale(moon.velocity, delta_time));

        printf("Moon position: (%f, %f, %f)\n", moon.position.x, moon.position.y, moon.position.z);

    }


}