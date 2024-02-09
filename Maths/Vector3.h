#pragma once

#include <iostream>

using namespace std;

// Right-Click on Solution >> Add New Project >> C++ Static Library >> "Maths"
// Right-Click on Solution >> Add New Project >> GoogleTest (Target: Maths) >> "Maths.Test"
// Right-Click on Maths >> Add New Class >> "Vector3"
// Right-Click on test.cpp >> Rename to "Vector3Test.cpp"
// Find the Code for Vector3Test.cpp and for Vector.h on Discord

// Goal: Write a Unit Test to test one Vector Class Feature
//        e.g. Vector3(1, 2, 3) + Vector3(4, 5, 6) = Vector3(5, 7, 9)
// Then: Implement the Vector Class Feature
//        e.g. return Vector3(x + other.x, ...
// Do this for Vector3(float, float, float), ==, !=, -V3, V3*float, V3/float, V3+V3, V3-V3,
//    float magnitude()

class Vector3
{
public:
	float x, y, z;
	Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } {}

	bool operator==(const Vector3& other) const {
		return x == other.x && y == other.y && z == other.z;
	}
	
	bool operator!=(const Vector3& other) const {
		return x != other.x || y != other.y || z != other.z;
	}
	
	Vector3 operator-() const {
		// return new vector where all components are negated
		return Vector3(-x,-y,-z);
	}

	Vector3 operator+(const Vector3& other) const {
		// return new vector where all components are negated
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	Vector3 operator-(const Vector3& other) const {
		// return new vector where all components are negated
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	Vector3 operator*(float f) const {
		// return new vector where all components are negated
		return Vector3(x * f, y * f, z * f);
	}

	Vector3 operator/(float f) const {
		// return new vector where all components are negated
		return Vector3(x / f, y / f, z / f);
	}

	float Magnitude() const {
		return sqrt(x * x + y * y + z * z);
	}

	float SquareMagnitude() const {
		return x * x + y * y + z * z;
	}

	static float Dot(const Vector3 a, const Vector3 b) {
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	static Vector3 Cross(const Vector3 a, const Vector3 b) {
		return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}

	Vector3 Normalize() const {
		return Vector3(x, y, z) / Vector3(x, y, z).Magnitude();
	}

	static float Distance(const Vector3 to, const Vector3 from) {
		return (to - from).Magnitude();
	}
};
/*
static Vector3 operator*(float f, const Vector3& v) {
	return v * k;
}
*/