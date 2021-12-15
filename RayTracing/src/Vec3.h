#pragma once
#include <cmath>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

class Vec3
{
public:

	Vec3() : v{ 0.0f, 0.0f, 0.0f } {}
	Vec3(float x, float y, float z) : v{ x, y, z } {}

	float x() const { return v[0]; }
	float y() const { return v[1]; }
	float z() const { return v[2]; }

	Vec3 operator-() const { return Vec3(-v[0], -v[1], -v[2]); }
	float& operator[](int i) { return v[i]; }
	
	Vec3& operator+=(const Vec3& e) {
		v[0] += e.x();
		v[1] += e.y();
		v[2] += e.z();
		return *this;
	}

	Vec3& operator*=(const float t) {
		v[0] *= t;
		v[1] *= t;
		v[2] *= t;
		return *this;
	}

	Vec3& operator/=(const float t) {
		return *this *= 1 / t;
	}

	float length() const {
		return sqrt(length_squared());
	}

	float length_squared() const {
		return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	}

private:
	float v[3];
};

// Type aliases for vec3
using Point3 = Vec3;   // 3D point
using Color = Vec3;    // RGB color