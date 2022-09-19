#include "Vector3.h"
#include <iostream>
#include <cmath>
using namespace std;

Vector3
Vector3::Add(const Vector3& other) const
{
    Vector3 retval;
    retval.X = X + other.X;
    retval.Y = Y + other.Y;
    retval.Z = Z + other.Z;
    return retval;
}

Vector3 
Vector3::Subtract(const Vector3& other) const
{
    Vector3 retval;
    retval.X = X - other.X;
    retval.Y = Y - other.Y;
    retval.Z = Z - other.Z;
    return retval;
}

Vector3 
Vector3::Multiply(float value) const
{
    Vector3 retval;
    retval.X = X * value;
    retval.Y = Y * value;
    retval.Z = Z * value;
    return retval;
}

Vector3 
Vector3::Divide(float value) const
{
    Vector3 retval;
    retval.X = X / value;
    retval.Y = Y / value;
    retval.Z = Z / value;
    return retval;
}

float 
Vector3::Length() const
{
    return sqrt(X * X + Y * Y + Z * Z);
}

Vector3 
Vector3::operator+(const Vector3& other) const
{
    return Add(other);
}
Vector3 
Vector3::operator-(const Vector3& other) const
{
    return Subtract(other);
}
Vector3 
Vector3::operator*(float value) const
{
    return Multiply(value);
}
Vector3 
Vector3::operator/(float value) const
{
    return Divide(value);
}