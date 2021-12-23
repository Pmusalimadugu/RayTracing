#include <iostream>
#include <fstream>

#include "RayTracing.h"
#include "HittableList.h"
#include "Sphere.h"
#include "Color.h"

#define print(x) image << x 
#define println(x) image << x << "\n"


Color rayColor(const Ray& r, const Hittable& world) {
	HitRecord record;
	if (world.hit(r, 0, infinity, record)) {
		return 0.5 * (record.normal + Color(1, 1, 1));
	}
	Vec3 unitDirection = unit_vector(r.getDirection());
	auto t = 0.5 * (unitDirection.y() + 1.0);
	return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main()
{

	// Image

	const float aspectRatio = 16.0f / 9.0f;
	const int imageWidth = 1920;
	const int imageHeight = static_cast<int>(imageWidth / aspectRatio);

	// World
	HittableList world;
	world.add(make_shared<Sphere>(Point3(0, 0, -1), 0.5));
	world.add(make_shared<Sphere>(Point3(0, 0.5, -1), 0.25));
	world.add(make_shared<Sphere>(Point3(0, 0.75, -1), 0.125));
	world.add(make_shared<Sphere>(Point3(0, -100.5, -1), 100));

	// Camera

	float vh = 2.0f;
	float vw = aspectRatio * vh;
	float focalLength = 1.0f;

	auto origin = Point3(0, 0, 0);
	auto horizontal = Vec3(vw, 0, 0);
	auto vertical = Vec3(0, vh, 0);
	auto lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLength);

	std::ofstream image;

	image.open("image.ppm");

	println("P3");
	print(imageWidth);
	print(" ");
	println(imageHeight);
	println("255");


	for (int j = imageHeight - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines progress: " << float(imageHeight-j)*100/imageHeight << '%' << std::flush;
		for (int i = 0; i < imageWidth; ++i)
		{
			auto u = float(i) / (imageWidth - 1);
			auto v = float(j) / (imageHeight - 1);
			Ray r = Ray(origin, lowerLeftCorner + u * horizontal + v * vertical);
			Color pixelColor = rayColor(r, world);
			writeColor(image, pixelColor);

		
		}

	}

	image.close();

	std::cerr << "\nDone.\n";


}
