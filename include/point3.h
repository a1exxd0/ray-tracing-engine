#ifndef POINT3_H
#define POINT3_H

#include "vec3.h"

namespace rte {

class point3 : vec3 {
public:
    point3() : vec3() {}
    point3(double e1, double e2, double e3) : vec3 (e1, e2, e3) {}

    point3 operator-() const { return point3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    point3& operator+=(const point3& v) {
        e[0] += v[0];
        e[1] += v[1];
        e[2] += v[2];
        return *this;
    }

    point3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    point3& operator/=(double t) {
        return *this *= 1/t;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

inline std::ostream& operator<<(std::ostream& out, const point3& v) {
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

inline point3 operator+(const point3& u, const point3& v) {
    return point3(u[0] + v[0], u[1] + v[1], u[2] + v[2]);
}

inline point3 operator-(const point3& u, const point3& v) {
    return point3(u[0] - v[0], u[1] - v[1], u[2] - v[2]);
}

inline point3 operator*(const point3& u, const point3& v) {
    return point3(u[0] * v[0], u[1] * v[1], u[2] * v[2]);
}

inline point3 operator*(double t, const point3& v) {
    return point3(t*v[0], t*v[1], t*v[2]);
}

inline point3 operator*(const point3& v, double t) {
    return t * v;
}

inline point3 operator/(const point3& v, double t) {
    return (1/t) * v;
}

inline double dot(const point3& u, const point3& v) {
    return u[0] * v[0]
         + u[1] * v[1]
         + u[2] * v[2];
}

inline point3 cross(const point3& u, const point3& v) {
    return point3(u[1] * v[2] - u[2] * v[1],
                u[2] * v[0] - u[0] * v[2],
                u[0] * v[1] - u[1] * v[0]);
}

inline point3 unit_vector(const point3& v) {
    return v / v.length();
}

inline bool operator==(const point3& v, const point3& u) {
    return (
        v[0] == u[0] && v[1] == u[1] && v[2] == u[2]
    );
}

}
#endif