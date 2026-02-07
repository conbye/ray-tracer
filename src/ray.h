#ifndef ray_h
#define ray_h

#include "vec3.h"

class ray {
private:
    vec3 origin;
    vec3 direction;
public:
    // Constructors
    ray();
    ray(const vec3 o, const vec3 d);
    ray(const ray& other);
    ray(ray&& other);
    ray& operator =(ray other);

    // Get properties
    const vec3& origin() const;
    const vec3& dir() const;

    vec3 cast(double t) const;
}

#endif
