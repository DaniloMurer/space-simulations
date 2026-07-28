#include <physics/vector3.h>
#include <math.h>

SimVector3 vector3_add(SimVector3 a, SimVector3 b)
{
    return (SimVector3){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z};
}

SimVector3 vector3_subtract(SimVector3 a, SimVector3 b)
{
    return (SimVector3){
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z};
}

double vector3_magnitude(SimVector3 a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

SimVector3 vector3_normalize(SimVector3 a, double magnitude)
{
    return (SimVector3){
        .x = a.x / magnitude,
        .y = a.y / magnitude,
        .z = a.z / magnitude};
}

SimVector3 vector3_scale(SimVector3 a, double scalar)
{
    return (SimVector3){
        .x = a.x * scalar,
        .y = a.y * scalar,
        .z = a.z * scalar};
}
