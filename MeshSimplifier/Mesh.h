#pragma once
#include <vector>
#include "Face.h"
#include "Vector3.h"
#include <list>

using namespace std;

class Mesh
{
public:
	vector<Face> faces;
	vector<Vertex> vertices;

	list<int> find_triangles_sharing_vertex(uint32_t vertexIndex);
	void remove_vertex_by_index(uint32_t vertexIndex);
	void remove_degenerated_triangles();
};
