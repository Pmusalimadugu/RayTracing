#include <iostream>
#include <fstream>
#include <chrono>
#include "Vec3.h"
#include "Color.h"
#include "Ray.h"

#define print(x) image << x 
#define println(x) image << x << "\n"

bool hit_sphere(const Point3& center, float radius, const Ray& r) {
	Vec3 oc = r.getOrigin() - center;
	float a = dot(r.getDirection(), r.getDirection());
	float b = 2.0f * dot(oc, r.getDirection());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}


// from online code
Color ray_color(const Ray& r) {
	if (hit_sphere(Point3(0.0f, 0.0f, -1.0f), 0.5f, r))
		return Color(1, 0, 0);;
	Vec3 unit_direction = unit_vector(r.getDirection());
	float t = 0.5f * (unit_direction.y() + 1.0f);
	return (1.0f - t) * Color(1.0f, 1.0f, 1.0f) + t * Color(0.5f, 0.7f, 1.0f);
}
int main() {

	std::ofstream image;

	image.open("image.ppm");


	// Image
	const auto aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	// Camera

	float viewport_height = 2.0f;
	float viewport_width = aspect_ratio * viewport_height;
	float focal_length = 1.0;

	Point3 origin = Point3();
	Vec3 horizontal = Vec3(viewport_width, 0, 0);
	Vec3 vertical = Vec3(0, viewport_height, 0);
	Vec3 lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focal_length);


	auto start = std::chrono::high_resolution_clock::now();


	println("P3");
	print(image_width);
	print(" ");
	println(image_height);
	println("255");


	for (int c = 0; c < image_height; c++) {

		std::cout << "\rScanlines progress: " << (float)100*c/image_height << '%' << std::flush;

		for (int r = 0; r < image_width; r++) {
			float u = float(r) / (image_width - 1);
			float v = float(c) / (image_height - 1);
			Ray mainRay = Ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
			Color pixel_color = ray_color(mainRay);
			write_color(image, pixel_color);
		}

	}

	image.close();

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

	std::cout << "\nDone. Render took " << duration.count() << " ms.";


}
