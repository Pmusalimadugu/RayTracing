#pragma once

#include "Vec3.h"
#include <fstream>
#include <iostream>

void write_color(std::ofstream& image, Color pixel_color) {
    // Write the translated [0,255] value of each color component.
    image << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}
