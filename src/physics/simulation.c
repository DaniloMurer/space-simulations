#include "physics/simulation.h"
#include "physics/newtonian_gravity.h"
#include "physics/vector3.h"
#include <stdio.h>

void simulate_earth_moon_system(Universe *universe)
{
    printf("Moon position: (%f, %f, %f)\n", universe->bodies[1]->position.x, universe->bodies[1]->position.y, universe->bodies[1]->position.z);

    const double delta_time = 0.016;
    for (int i = 0; i < 100; i++) {
        const SimVector3 direction = vector3_subtract(universe->bodies[0]->position, universe->bodies[1]->position);

        const double distance = vector3_magnitude(direction);

        const SimVector3 normalized_direction = vector3_normalize(direction, distance);

        const double force_scalar = newtonian_gravity_force(universe->bodies[0]->mass, universe->bodies[1]->mass, distance);

        const SimVector3 force = vector3_scale(normalized_direction, force_scalar);

        printf("Force: (%f, %f, %f)\n", force.x, force.y, force.z);

        const SimVector3 moon_acceleration = vector3_scale(force, 1.0 / universe->bodies[1]->mass);

        universe->bodies[1]->velocity = vector3_add(universe->bodies[1]->velocity, vector3_scale(moon_acceleration, delta_time));

        universe->bodies[1]->position = vector3_add(universe->bodies[1]->position, vector3_scale(universe->bodies[1]->velocity, delta_time));

        printf("Moon position: (%f, %f, %f)\n", universe->bodies[1]->position.x, universe->bodies[1]->position.y, universe->bodies[1]->position.z);

    }


}