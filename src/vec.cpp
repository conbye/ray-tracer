#include <cmath>
#include "vec.h"

// vec3 Implementation
vec3::vec3() { data = {0.0, 0.0, 0.0}; }

vec3::vec3(double x, double y, double z) { data = {x, y, z}; }

vec3::vec3(const vec3& other) { data = {other.x(), other.y(), other.z()}; }
vec3::vec3(const vec3&& other) { data = {other.x(), other.y(), other.z()}; }

vec3& vec3::operator =(vec3 other) { 
    other.swap(*this); 
    return *this; 
}

double vec3::x() const { return data[0]; }
double vec3::y() const { return data[1]; }
double vec3::z() const { return data[2]; }

vec3 vec3::operator +(const vec3& other) const { return vec3(x() + other.x(), y() + other.y(), z() + other.z()); }
vec3 vec3::operator -(const vec3& other) const { return vec3(x() - other.x(), y() - other.y(), z() - other.z()); }
vec3 vec3::operator *(const vec3& other) const { return vec3(x() * other.x(), y() * other.y(), z() * other.z()); }

friend vec3 vec3::operator *(const double lhs, const vec3& rhs) const {
    return vec3(lhs * rhs.x(), lhs * rhs.y(), lhs * rhs.z())
}
vec3 vec3::operator /(const double scalar) const { return vec3(x() / scalar, y() / scalar(), z() / scalar); }

double vec3::mag() const { return std::sqrt(dot(*this, *this)); }
double vec3::is_normal() const { return mag() == 1.0; }
vec3 vec3::normalized() const { return (*this / mag()); } 

double vec3::dot(vec3& vec, vec3& other) { return vec.x() * other.x() + vec.y() * other.y() + vec.z() * other.z(); }

double vec3::cross(vec3& vec, vec3& other) {
   return vec3(vec.y() * other.z() - vec.z() * other.y(),
               vec.z() * other.x() - vec.x() * other.z(),
               vec.x() * other.y() - vec.y() * other.x());
}

// mat3 Implementation
mat3::mat3() {
    data = {{1.0, 0.0, 0.0},
            {0.0, 1.0, 0.0},
            {0.0, 0.0, 1.0}};
}

mat3::mat3(double xi, double yi, double zi,
           double xj, double yj, double zj,
           double xk, double yk, double zk) {
    data = {{xi, yi, zi},
            {xj, yj, zj},
            {xk, yk, zk}};
}

mat3::mat3(const vec3& vec) {
    data = {{vec.x(), 0.0, 0.0},
            {0.0, vec.y(), 0.0},
            {0.0, 0.0, vec.z()}};
}

mat3::mat3(const vec3&& vec) {
    data = {{vec.x(), 0.0, 0.0},
            {0.0, vec.y(), 0.0},
            {0.0, 0.0, vec.z()}};
}

mat3::mat3(const mat3& other) {
    data = {{other.xi(), other.yi(), other.zi()},
            {other.xj(), other.yj(), other.zj()},
            {other.xk(), other.yk(), other.zk()}};
}

mat3::mat3(const mat3&& other) {
    data = {{other.xi(), other.yi(), other.zi()},
            {other.xj(), other.yj(), other.zj()},
            {other.xk(), other.yk(), other.zk()}};
}

mat3& mat3::operator =(mat3 other) { 
    other.swap(*this); 
    return *this; 
}

double mat3::xi() const { return data[0][0]; }
double mat3::yi() const { return data[0][1]; }
double mat3::zi() const { return data[0][2]; }
                  
double mat3::xj() const { return data[1][0]; }
double mat3::yj() const { return data[1][1]; }
double mat3::zj() const { return data[1][2]; }
                  
double mat3::xk() const { return data[2][0]; }
double mat3::yk() const { return data[2][1]; }
double mat3::zk() const { return data[2][2]; }

mat3 mat3::operator +(const mat3& other) const {
    return mat3(xi() + other.xi(), yi() + other.yi(), zi() + other.zi(),
                xj() + other.xj(), yj() + other.yj(), zj() + other.zj(),
                xk() + other.xk(), yk() + other.yk(), zk() + other.zk());
}

mat3 mat3::operator -(const mat3& other) const {
    return mat3(xi() - other.xi(), yi() - other.yi(), zi() - other.zi(),
                xj() - other.xj(), yj() - other.yj(), zj() - other.zj(),
                xk() - other.xk(), yk() - other.yk(), zk() - other.zk());
}

mat3 mat3::operator *(const mat3& other) const {
    return mat3(xi() * other.xi(), yi() * other.xj(), zi() * other.zk(),
                xj() * other.yi(), yj() * other.yj(), zj() * other.yk(),
                xk() * other.zi(), yk() * other.zj(), zk() * other.zk());
}

vec3 mat3::operator *(const vec3& other) const {
    return vec3(xi() * other.x() + yi() * other.y() + zi() * other.z(),
                xj() * other.x() + yj() * other.y() + zj() * other.z(),
                xk() * other.x() + yk() * other.y() + zk() * other.z());
}

mat3::transpose() const {
    return mat3(xi(), xj(), xk(),
                yi(), yj(), yk(),
                zi(), zj(), zk());
}

Rotator::Rotator() {
    alpha = 0;
    beta = 0;
    gamma = 0;
    mat = {{1.0, 0.0, 0.0},
           {0.0, 1.0, 0.0},
           {0.0, 0.0, 1.0}};
}

Rotator::Rotator(double a, double b, double g) {
    alpha = a;
    double cos_a = std::cos(a);
    double sin_a = std::sin(a);
    beta = b;
    double cos_b = std::cos(b);
    double sin_b = std::sin(b);
    gamma = g;
    double cos_g = std::cos(g);
    double sin_g = std::sin(g);
    mat = {{cos_a * cos_b, cos_a * sin_b * sin_g - sin_a * cos_g, cos_a * sin_b * cos_g + sin_a * sin_g},
           {sin_a * cos_b, sin_a * sin_b * sin_g - cos_a * cos_g, sin_a * sin_b * cos_g + cos_a * sin_g},
           {-sin_b, cos_b * sin_g, cos_b * cos_g}};
}

vec3 Rotator::rotate(vec3& vec) {
    return mat * vec;
}
