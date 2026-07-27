#ifndef VECTOR3_H
#define VECTOR3_H

typedef struct
{
    double x;
    double y;
    double z;
} SimVector3;

SimVector3 vector3_add(SimVector3 a, SimVector3 b);
SimVector3 vector3_subtract(SimVector3 a, SimVector3 b);

#endif // VECTOR3_H