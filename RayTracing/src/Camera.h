#pragma once
#include "Vec3.h"
class Camera {
public:

	Camera()
		: location(Point3(0.0f, 0.0f, 0.0f)), height(1280), width(720), aspect_ratio(width / height) {}

	Camera(Point3& location, int height, int width)
		: location(location), height(height), width(width), aspect_ratio(width/height) {}

public:
	Point3 location;
	int height, width, vh, vw;
	int aspect_ratio; 

};