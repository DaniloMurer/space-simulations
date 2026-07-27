#include <physics/vector3.h>

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
