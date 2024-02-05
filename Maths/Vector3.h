#pragma once
class Vector3
{
public:
	float x, y, z;
	Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } {}

	bool operator==(const Vector3& other) {
		return x == other.x, y == other.y, z == other.z;
	}
};

