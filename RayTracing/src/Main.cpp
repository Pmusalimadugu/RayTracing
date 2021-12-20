#include <iostream>
#include <fstream>
#include "Vec3.h"
#include "Color.h"
#include "Ray.h"

#define print(x) image << x 
#define println(x) image << x << "\n"

bool hit_sphere(const Point3& center, double radius, const Ray& r) {
	Vec3 oc = r.getOrigin() - center;
	auto a = dot(r.getDirection(), r.getDirection());
	auto b = 2.0 * dot(oc, r.getDirection());
	auto c = dot(oc, oc) - radius * radius;
	auto discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}


// from online code
Color ray_color(const Ray& r) {
	if (hit_sphere(Point3(0, 0, -1), 1, r))
		return Color(1, 0, 0);
	Vec3 unit_direction = unit_vector(r.getDirection());
	auto t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}
int main() {
	std::ofstream image;

	image.open("image.ppm");


	// Image
	const auto aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	// Camera

	auto viewport_height = 2.0;
	auto viewport_width = aspect_ratio * viewport_height;
	auto focal_length = 1.0;

	auto origin = Point3(0, 0, 0);
	auto horizontal = Vec3(viewport_width, 0, 0);
	auto vertical = Vec3(0, viewport_height, 0);
	auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focal_length);


	println("P3");
	print(image_width);
	print(" ");
	println(image_height);
	println("255");


	for (int c = 0; c < image_height; c++) {

		std::cerr << "\rScanlines progress: " << (float)100*c/image_height << '%' << std::flush;

		for (int r = 0; r < image_width; r++) {
			auto u = double(r) / (image_width - 1);
			auto v = double(c) / (image_height - 1);
			Ray mainRay(origin, lower_left_corner + u * horizontal + v * vertical - origin);
			Color pixel_color = ray_color(mainRay);
			write_color(image, pixel_color);
		}

	}

	image.close();

	std::cerr << "\nDone.\n";


}
