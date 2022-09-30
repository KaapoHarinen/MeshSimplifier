#include "Face.h"
#include "Mesh.h"
#include <cstdint>
#include <set>

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