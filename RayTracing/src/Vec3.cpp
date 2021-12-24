#include "Vec3.h"
#include "RayTracing.h"



Vec3::Vec3() : e{ 0.0f, 0.0f, 0.0f } {}
Vec3::Vec3(float x, float y, float z) : e{ x, y, z } {}

float Vec3::x() const { return e[0]; }
float Vec3::y() const { return e[1]; }
float Vec3::z() const { return e[2]; }

Vec3 Vec3::operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
float& Vec3::operator[](int i) { return e[i]; }
Vec3& Vec3::operator+=(const Vec3& u) {
	e[0] += u.x();
	e[1] += u.y();
	e[2] += u.z();
	return *this;
}
Vec3& Vec3::operator*=(const float t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}
Vec3& Vec3::operator/=(const float t) {
	return *this *= 1 / t;
}
float Vec3::length() const {
	return sqrt(length_squared());
}
float Vec3::length_squared() const {
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

inline Vec3 Vec3::random() {
	return Vec3(randFloat(), randFloat(), randFloat());
}

inline Vec3 Vec3::random(double min, double max) {
	return Vec3(randFloat(min, max), randFloat(min, max), randFloat(min, max));
}

Vec3 randomInUnitSphere() {
	while (true) {
		auto p = Vec3::random(-1, 1);
		if (p.length_squared() >= 1) continue;
		return p;
	}
}

Vec3 randomUnitVector() {
	return unit_vector(randomInUnitSphere());
}




