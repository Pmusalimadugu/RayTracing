#include <iostream>
#include <fstream>
#include "Vec3.h"
#include "Color.h"
#include "Ray.h"

#define print(x) image << x 
#define println(x) image << x << "\n"

// from online code
Color ray_color(const Ray& r) {
	Vec3 unit_direction = unit_vector(r.getDirection());
	auto t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main() {
	std::ofstream image;

	image.open("image.ppm");

	const int image_height = 1000;
	const int image_width = 1000; 

	println("P3");
	print(image_height);
	print(" ");
	println(image_width);
	println("255");


	for (int r = 0; r < image_width; r++) {

		std::cerr << "\rScanlines progress: " << (float)100*r/image_width << '%' << std::flush;

		for (int c = 0; c < image_height; c++) {
			Color pixel_color(float(r) / (image_width - 1), float(c) / (image_height - 1), 0.25);
			write_color(image, pixel_color);
		}

	}

	image.close();

	std::cerr << "\nDone.\n";


}
