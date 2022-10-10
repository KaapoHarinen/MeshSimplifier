#include "Mesh.h"
#include <iostream>

using namespace std;

list<int>
Mesh::find_triangles_sharing_vertex(uint32_t vertexIndex)
{
	list<int> triangles;
	for (size_t i = 0; i < faces.size(); i++)
	{
		if (faces[i].a == vertexIndex ||
			faces[i].b == vertexIndex ||
			faces[i].c == vertexIndex)
		{
			triangles.push_back(i);
		}
	}
	return triangles;
}

void
Mesh::remove_vertex_by_index(uint32_t vertexIndex)
{
	list<int> triangles = find_triangles_sharing_vertex(vertexIndex);
	for (int i : triangles)
	{
		faces[i].MergeVertex(vertexIndex);
	}
	vertices.erase(vertices.begin() + vertexIndex);

	for (Face& f : faces)
	{
		if (f.a >= vertexIndex) f.a -= 1;
		if (f.b >= vertexIndex) f.b -= 1;
		if (f.c >= vertexIndex) f.c -= 1;
	}
}

void
Mesh::remove_degenerated_triangles()
{
	list<size_t> facesToBeRemoved;

	for (size_t i = 0; i < faces.size(); i++)
	{
		if (faces[i].is_degenerated(*this)) facesToBeRemoved.push_back(i);
	}

	facesToBeRemoved.sort();

	while (facesToBeRemoved.empty() == false)
	{

		faces.erase(faces.begin() + facesToBeRemoved.back());
		facesToBeRemoved.pop_back();
	}
}

void
Mesh::remove_smallest_triangle()
{
	float minArea = faces[0].GetArea(*this);
	size_t minFace = 0;

	for (size_t i = 1; i < faces.size(); i++)
	{
		float tmp = faces[i].GetArea(*this);
		if (tmp < minArea)
		{
			minFace = i;
			minArea = tmp;
		}
	}

	faces.erase(faces.begin() + minFace);
}
