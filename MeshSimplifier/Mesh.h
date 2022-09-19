#pragma once
#include <vector>
#include "Face.h"
#include "Vector3.h"

class Mesh
{
	std::vector<Face> faces;
	std::vector<Vertex> verticles;
};