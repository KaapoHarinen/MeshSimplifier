#pragma once
#include <cstdint>
#include <ostream>
#include "Mesh.h"

class Mesh;

class Face
{
public:
	uint32_t a;
	uint32_t b;
	uint32_t c;

	inline void MergeVertex(uint32_t v)
	{
		if (a = v)
		{
			a = b;
		}
		else if (b = v)
		{
			b = a;
		}
		else if (c = v)
		{
			c = a;
		}
	}

	bool is_degenerated(Mesh& mesh);
};

inline std::ostream& operator<<(std::ostream& s, const Face& f)
{
	s << f.a << ", " << f.b << ", " << f.c;
	return s;
}