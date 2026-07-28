#ifndef VECTOR3_H
#define VECTOR3_H

typedef struct SimVector3
{
    double x;
    double y;
    double z;
} SimVector3;

SimVector3 vector3_add(SimVector3 a, SimVector3 b);
SimVector3 vector3_subtract(SimVector3 a, SimVector3 b);
double vector3_magnitude(SimVector3 a);
SimVector3 vector3_normalize(SimVector3 a, double magnitude);
SimVector3 vector3_scale(SimVector3 a, double scalar);

#endif // VECTOR3_H