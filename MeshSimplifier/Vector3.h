#pragma once
#include <ostream>
class Vector3
{
public:
	float X;
	float Y;
	float Z;

	Vector3 Add(const Vector3& other) const;
	Vector3 Subtract(const Vector3& other) const;
	Vector3 Multiply(float value) const;
	Vector3 Divide(float value) const;
	float Length() const;

	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3 operator*(float value) const;
	Vector3 operator/(float value) const;
};
inline std::ostream& operator<<(std::ostream& s, const Vector3& v)
{
	s << v.X << ", " << v.Y << ", " << v.Z;
		return s;
}

typedef Vector3 Vertex;