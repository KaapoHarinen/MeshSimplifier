#pragma once
#include <cstdint>
#include <ostream>

class Face
{
public:
	uint32_t a;
	uint32_t b;
	uint32_t c;
};

inline std::ostream& operator<<(std::ostream& s, const Face& f)
{
	s << f.a << ", " << f.b << ", " << f.c;
	return s;
}