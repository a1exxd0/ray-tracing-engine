#ifndef COLOR3_H
#define COLOR3_H

#include "vec3.h"

namespace rte {

class color3 : vec3 {
public:
    color3() : vec3() {}
    color3(double e1, double e2, double e3) : vec3 (e1, e2, e3) {}

    color3 operator-() const { return color3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    color3& operator+=(const color3& v) {
        e[0] += v[0];
        e[1] += v[1];
        e[2] += v[2];
        return *this;
    }

    color3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    color3& operator/=(double t) {
        return *this *= 1/t;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

inline std::ostream& operator<<(std::ostream& out, const color3& v) {
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

inline color3 operator+(const color3& u, const color3& v) {
    return color3(u[0] + v[0], u[1] + v[1], u[2] + v[2]);
}

inline color3 operator-(const color3& u, const color3& v) {
    return color3(u[0] - v[0], u[1] - v[1], u[2] - v[2]);
}

inline color3 operator*(const color3& u, const color3& v) {
    return color3(u[0] * v[0], u[1] * v[1], u[2] * v[2]);
}

inline color3 operator*(double t, const color3& v) {
    return color3(t*v[0], t*v[1], t*v[2]);
}

inline color3 operator*(const color3& v, double t) {
    return t * v;
}

inline color3 operator/(const color3& v, double t) {
    return (1/t) * v;
}

inline double dot(const color3& u, const color3& v) {
    return u[0] * v[0]
         + u[1] * v[1]
         + u[2] * v[2];
}

inline color3 cross(const color3& u, const color3& v) {
    return color3(u[1] * v[2] - u[2] * v[1],
                u[2] * v[0] - u[0] * v[2],
                u[0] * v[1] - u[1] * v[0]);
}

inline color3 unit_vector(const color3& v) {
    return v / v.length();
}

inline bool operator==(const color3& v, const color3& u) {
    return (
        v[0] == u[0] && v[1] == u[1] && v[2] == u[2]
    );
}

}
#endif