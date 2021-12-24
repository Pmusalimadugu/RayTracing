#include  "RayTracing.h"
#include "Color.h"


void writeColor(std::ofstream& image, Color pixelColor, int samplesPerPixel) {

    auto r = pixelColor.x();
    auto g = pixelColor.y();
    auto b = pixelColor.z();

    auto scale = 1.0f / samplesPerPixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    // Write the translated [0,255] value of each color component.
    image << static_cast<int>(256 * clamp(r, 0.0, 0.999f)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999f)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999f)) << '\n';
}
