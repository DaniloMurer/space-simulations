#ifndef SIMULATION_H
#define SIMULATION_H

#include <physics/vector3.h>

typedef struct Body {
    SimVector3 position;
    SimVector3 velocity;
    double mass;
} Body;

void simulate_earth_moon_system();

#endif
