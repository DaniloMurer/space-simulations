
#include "physics/newtonian_gravity.h"

double newtonian_gravity_force(double mass1, double mass2, double distance) {
    //const double G = 6.67430e-11;
    const double G = 5000;
    return (G * mass1 * mass2) / (distance * distance);
}
