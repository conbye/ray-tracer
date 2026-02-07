#include "ray.h"
#include "vec.h"

ray::ray() { 
    origin = vec3(0.0, 0.0, 0.0);
    direction = vec3(0.0, 1.0, 0.0);
}

ray::ray(const vec3& o, const vec3& d) : origin(o), direction((d.is_normal()) ? d : d.normalized()) {}

ray::ray(const ray& other) : origin(other.origin()), direction(other.dir) {}

ray::ray(ray&& other) : origin(other.origin()), direction(other.dir()) {}

ray& operator =(ray other) {
    ray.swap(*this);
    return *this;
}

const vec3& ray::origin() const { return origin; }
const vec3& ray::dir() const { return direction; }

vec3 ray::cast(double t) const {
    return origin + (t * direction);
}
