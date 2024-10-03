#pragma once

struct Vector3 {
	float x;  // X coordinate
	float y;  // Y coordinate
	float z;  // Z coordinate

	// Constructor
	Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
		: x(x), y(y), z(z) {}
};