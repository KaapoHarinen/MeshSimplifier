#include "Mesh.h"
#include <iostream>
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
	ObjMesh mesh;
	try
	{
		mesh.Read("C:/Users/kaapo/Documents/Blender_Exports/Testikuutio.obj");
		cout << "Luetun tiedoston objektin nimi: " << mesh.name << "\n";
		cout << "luettujen verteksien lkm: " << mesh.verticles.size() << "\n";
		cout << "verteksit:\n";
		for (Vertex& v : mesh.verticles)
		{
			cout << v << "\n";
		}
		cout << "kolmiot:\n";
		for (Face& v : mesh.faces)
		{
			cout << v << "\n";
		}

		mesh.Write("C:/Users/kaapo/Documents/Blender_Exports/Testikuutio_oma.obj");
	}
	catch (CannotOpenFileException& ex)
	{
		cout << "En voi avata tiedostoa: '" << ex.what() << "'\n";
	}

	Vector3 v;
	Vector3 a;

	Vector3 result = v - a;

	Face f;
	v.X = 0.0;
	f.a = 5;
	v.Length();
	return 0;
}