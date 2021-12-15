#pragma once
#include <cmath>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

class Vec3 {
public:

	Vec3() : e{ 1.0f, 2.0f, 3.0f } {}
	Vec3(float x, float y, float z) : e{ x, y, z } {}
	__device__
	float x() const { return e[0]; }
	__device__
	float y() const { return e[1]; }
	__device__
	float z() const { return e[2]; }


	Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
	float& operator[](int i) { return e[i]; }

	__device__
	Vec3& operator+=(const Vec3& u) {
		e[0] += u.x();
		e[1] += u.y();
		e[2] += u.z();
		return *this;
	}

	__device__
	Vec3& operator*=(const float t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}
	

	__device__
	Vec3& operator/=(const float t) {
		return *this *= 1 / t;
	}

	__device__
	float length() const {
		return sqrt(length_squared());
	}

	__device__
	float length_squared() const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}



public:
	float e[3];
};

inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vec3 operator+(const Vec3& u, const Vec3& v) {
	return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline Vec3 operator-(const Vec3& u, const Vec3& v) {
	return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline Vec3 operator*(const Vec3& u, const Vec3& v) {
	return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline Vec3 operator*(float t, const Vec3& v) {
	return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vec3 operator*(const Vec3& v, float t) {
	return t * v;
}

inline Vec3 operator/(Vec3 v, float t) {
	return (1 / t) * v;
}

inline double dot(const Vec3& u, const Vec3& v) {
	return u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2];
}

inline Vec3 cross(const Vec3& u, const Vec3& v) {
	return Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
		u.e[2] * v.e[0] - u.e[0] * v.e[2],
		u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline Vec3 unit_vector(Vec3 v) {
	return v / v.length();
}


// Type aliases for vec3
using Point3 = Vec3;   // 3D point
using Color = Vec3;    // RGB color