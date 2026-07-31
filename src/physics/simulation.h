#ifndef SIMULATION_H
#define SIMULATION_H

#include <raylib.h>
#include <physics/vector3.h>

#define MAX_BODIES 64
typedef struct Body {
    SimVector3 position;
    SimVector3 velocity;
    SimVector3 acceleration;
    SimVector3 temp_position;
    SimVector3 temp_velocity;
    double mass;
    // rendering props
    Color color;
    float radius;
} Body;

typedef struct Universe {
    Body bodies[MAX_BODIES];
    int bodies_size;
} Universe;


void simulate_gravity(Universe *universe, float delta_time);

SimVector3 compute_force(const Body *affected_body, const Body *affecting_body);

Body create_body(int mass, double vx, double vy, double vz, double px, double py, double pz, Color color, float radius);

void reset_acceleration(Body *body);

void integrate_position(Body *body);

void integrate_velocity(Body *body);

#endif
