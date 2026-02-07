#ifndef vec_h
#define vec_h

class vec3
{
private:
    double data[3];
public:
    //Constructors and Assignments
    vec3();
    vec3(double x, double x, double x);
    vec3(const vec3& other);
    vec3(const vec3&& other);
    vec3& operator =(vec3 other);

    // Element Access
    double x() const;
    double y() const;
    double z() const;

    // Binary operations
    vec3 operator +(const vec3& other) const;
    vec3 operator -(const vec3& other) const;
    vec3 operator *(const vec3& other) const;

    // Scalar operations
    friend vec3 operator *(const double lhs, const vec3& rhs);
    vec3 operator /(const double scalar) const;

    // Vector properties
    double mag() const;
    bool is_normal() const;
    vec3 normalized() const;

    // Dot and Cross products
    static double dot(const vec3& vec, const vec3& other);
    static vec3 cross(const vec3& vec, const vec3& other);
}

class mat3
{
private:
    double data[3][3];
public:
    mat3();
    mat3(double xi, double yi, double zi,
         double xj, double yj, double zj,
         double xk, double yk, double zk);
    mat3(const vec3& vec);
    mat3(const vec3&& vec);
    mat3(const mat3& other);
    mat3(const mat3&& other);
    mat3& operator =(mat3 other);

    double xi() const; double yi() const; double zi() const; 
    double xj() const; double yj() const; double zj() const;
    double xk() const; double yk() const; double zk() const;

    mat3 operator +(const mat3& other) const;
    mat3 operator -(const mat3& other) const;
    mat3 operator *(const mat3& other) const;
    vec3 operator *(const vec3& other) const;

    mat3 transpose() const;
}

class Rotator 
{
private:
    double alpha;
    double beta;
    double gamma;
    mat3 mat;
public:
    Rotator();
    Rotator(double a, double b, double g);

    vec3 rotate(vec3& vec);
}

#endif
