#include "camera.h"

camera::camera() {
    loc = vec3();
    look = vec3(0.0, 0.0, 1.0);
    u = vec3(0.0, 1.0, 0.0);
    v = vec3(1.0, 0.0, 0.0);

    rot_mat = mat3();
}

camera::camera(const vec3& _loc, const vec3& _dir, const vec3& _up) {
    loc = _loc;
    look = _dir;
    u = _up;
    v = -1.0 * vec3::cross(_dir, _up);

    rot_mat = mat3();
}

ray camera::cast_ray(double x, double y) {
    vec3 pixel_xy = look + x * u + y * v;
    return ray(loc, - loc);
}
