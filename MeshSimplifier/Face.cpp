#include "Face.h"
#include "Mesh.h"
#include <cstdint>
#include <set>
#include <cmath>

using namespace std;

const float EPSILON = 0.00001f;
bool Face::is_degenerated(Mesh& mesh)
{
	set<uint32_t> inique_indices;
	inique_indices.insert(a);
	inique_indices.insert(b);
	inique_indices.insert(c);

	bool indices_ok = inique_indices.size() == 3;

	if (indices_ok)
	{
		if ((mesh.vertices[a] - mesh.vertices[b]).Length() < EPSILON)
		{
			return true;
		}
		if ((mesh.vertices[a] - mesh.vertices[c]).Length() < EPSILON)
		{
			return true;
		}
		if ((mesh.vertices[b] - mesh.vertices[c]).Length() < EPSILON)
		{
			return true;
		}
		return false;
	}
	else
	{
		return true;
	}
}

float
Face::GetArea(Mesh& mesh) const
{
	Vertex vA = mesh.vertices[a];
	Vertex vB = mesh.vertices[b];
	Vertex vC = mesh.vertices[c];
	float lenAB = (vA - vB).Length();
	float lenAC = (vA - vC).Length();
	float lenCB = (vC - vB).Length();
	float semiperimeter = (lenAB + lenAC + lenCB) * 0.5;
	float area = sqrt(semiperimeter * (semiperimeter - lenAB) * (semiperimeter - lenAC) * (semiperimeter - lenCB));
	return area;
}