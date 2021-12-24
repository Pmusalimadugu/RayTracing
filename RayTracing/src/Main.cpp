#include <iostream>
#include <fstream>

#include "RayTracing.h"
#include "HittableList.h"
#include "Sphere.h"
#include "Color.h"
#include "Camera.h"	


#define print(x) image << x 
#define println(x) image << x << "\n"


Color rayColor(const Ray& r, const Hittable& world, int depth) {
	HitRecord record;

	if (depth <= 0)
		return Color(0, 0, 0);


	if (world.hit(r, 0.001f, infinity, record)) {
		Point3 target = record.p + record.normal + randomUnitVector();
		return 0.5 * rayColor(Ray(record.p, target - record.p), world, depth-1);
	}
	Vec3 unitDirection = unit_vector(r.getDirection());
	float t = 0.5f * (unitDirection.y() + 1.0f);
	return (1.0f - t) * Color(1.0f, 1.0f, 1.0f) + t * Color(0.5f, 0.7f, 1.0f);
}

int main()
{

	// Image

	const float aspectRatio = 16.0f / 9.0f;
	const int imageHeight = 1080;
	const int imageWidth = static_cast<int>(imageHeight * aspectRatio);

	//12x Antialiasing
	const int maxDepth = 100;	
	const int samplesPerPixel = 100;


	// World
	HittableList world;
	world.add(make_shared<Sphere>(Point3(0, 0, -1), 0.5));
	world.add(make_shared<Sphere>(Point3(0, 0.5, -1), 0.25));
	world.add(make_shared<Sphere>(Point3(0, 0.75, -1), 0.125));
	world.add(make_shared<Sphere>(Point3(0, -100.5, -1), 100));

	// Camera
	Camera camera = Camera();

	std::ofstream image;

	image.open("image.ppm");

	println("P3");
	print(imageWidth);
	print(" ");
	println(imageHeight);
	println("255");


	for (int j = imageHeight - 1; j >= 0; --j) {
		std::cerr << "\rScanlines progress: " << float(imageHeight-j)*100/imageHeight << '%' << std::flush;
		for (int i = 0; i < imageWidth; ++i) {
			Color pixelColor = Color(0.0f, 0.0f, 0.0f);
			for (int s = 0; s < samplesPerPixel; ++s) {
				auto u = (i + randFloat()) / (imageWidth - 1);
				auto v = (j + randFloat()) / (imageHeight - 1);
				Ray r = camera.getRay(u, v);
				pixelColor += rayColor(r, world, maxDepth);
			}
			writeColor(image, pixelColor, samplesPerPixel);


		
		}

	}

	image.close();

	std::cerr << "\nDone.\n";


}
