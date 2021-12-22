#pragma once
#include <cmath>


class Vec3 {
public:

	Vec3();
	Vec3(float x, float y, float z);
	float x() const;
	float y() const;
	float z() const;


	Vec3 operator-() const;
	float& operator[](int i);
	Vec3& operator+=(const Vec3& u);
	Vec3& operator*=(const float t);
	Vec3& operator/=(const float t);

	float length() const;
	float length_squared() const;

public:
	float e[3];
};

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

inline float dot(const Vec3& u, const Vec3& v) {
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