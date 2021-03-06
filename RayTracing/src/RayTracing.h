#pragma once

#include <cmath>
#include <limits>
#include <memory>


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

// Common Headers

#include "Ray.h"
#include "Vec3.h"
