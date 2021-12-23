#include "Camera.h"

Camera::Camera() {

	origin = Point3(0.0f, 0.0f, 0.0f);
	float aspectRatio = 16.0f / 9.0f;
	float vh = 2.0f;
	float vw = aspectRatio * vh;
	float focalLength = 1.0f;

	horizontal = Vec3(vw, 0, 0);
	vertical = Vec3(0, vh, 0);
	lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLength);
}
	

Ray Camera::getRay(float u, float v) const {
	return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}