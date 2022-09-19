#include "Mesh.h"
bool IsTerminator(const char* merkki)
{
	return (*merkki == '\0');
}

void SetTerminator(char& merkki)
{
	merkki = '\0';
}

bool IsEmpty(char merkki)
{
	return (merkki == ' ');
}

void SetEmpty(char* merkki)
{
	*merkki = '\0';
}

bool IsStar(const char& merkki)
{
	return merkki == '*';
}

void GetAddress(int* lahde, int koko, int* kohde[])
{
	for (int i = 0; i < koko; i++)
	{
		kohde[i] = &lahde[i];
	}
}

int main()
{
	Mesh mest;
	Vector3 v;
	Vector3 a;

	Vector3 result = v - a;

	Face f;
	v.X = 0.0;
	f.a = 5;
	v.Length();
	return 0;
}