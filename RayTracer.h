#ifndef RayTracer_h
#define RayTracer_h

#define MAX_THREADS 32

#include <stdio.h>

const uint32_t DEFAULT_WIDTH = 400;
const uint32_t DEFAULT_HEIGHT = 225;

class Scene;

class Pixel
{
public:    
    uint16_t color {0};
    int x {0};
    int y {0};

    Pixel();
    Pixel(uint8_t _color, int _x, int _y);
}

class RayTracer 
{
private:
    uint32_t screen_width {DEFAULT_WIDTH};
    uint32_t screen_height {DEFAULT_HEIGHT};
    vector<uint8_t> pixel_buffer;
    
    detect_surface(ray& ray_cast);
public:
    RayTracer();
    cast_ray(int x, int y);
}

#endif
