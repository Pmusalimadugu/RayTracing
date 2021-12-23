#pragma once

#include <cmath>
#include <limits>
#include <memory>
#include <random>


// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385f;

// Utility Functions

inline float degtoRad(float degrees) {
    return degrees * pi / 180.0f;
}

inline float randFloat() {
    static std::uniform_real_distribution<float> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline float clamp(float x, float min, float max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

// Common Headers

#include "Ray.h"
#include "Vec3.h"
