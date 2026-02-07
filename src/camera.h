#ifndef camera_h
#define camera_h

#include "vec3.h"
#include "ray.h"

#define DEFAULT_ASPECT_RATIO 16.0 / 9.0
#define DEFAULT_NORMALIZED_HEIGHT 1.0

class camera {
private:
    vec3 loc;
    vec3 look;
    vec3 u, v;

    mat3 rot_mat;
    double norm_height {DEFAULT_NORMALIZED_HEIGHT};
    double aspect_ratio {DEFAULT_ASPECT_RATIO};

    void update();
public:
    camera();
    camera(const vec3& _loc, const vec3& _dir, const vec3& _up);
    ray cast_ray(double x, double y);ZZ
    void move(const vec3& new_loc);
    void turn(double, double, double, double);
    void turn(const vec3& look_at, const vec3& up_dir);
    void set_fov(double);

    const vec3& loc() const { return loc; }
    const vec3& look() const { return loc; }
    const vec3& up() const { return u; }
    const vec3& right() const { return v; }

}
