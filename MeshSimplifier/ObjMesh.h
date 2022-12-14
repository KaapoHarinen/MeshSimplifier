#pragma once
#include <string>
#include <fstream>
#include "Errors.h"
#include "Mesh.h"
#include "ReadWriter.h"
using namespace std;

class ObjMesh : public Mesh, public ReaderWriter
{
public:
	string name;
	void Read(const string& path) override
	{
		ifstream file(path);
		if (file.bad() || file.fail())
		{
			throw CannotOpenFileException(path);
		}

		string line;
		while (getline(file, line))
		{
			//Verticles
			if (line[0] == 'v')
			{
				Vertex v;
				stringstream ss;
				ss << line.substr(2);
				float tmp;
				//X
				if (!(ss >> tmp)) throw ParseError("X-komponentin arvo ep?kelpo " + ss.str());
				v.X = tmp;
				//Y
				if (!(ss >> tmp)) throw ParseError("Y-komponentin arvo ep?kelpo " + ss.str());
				v.Y = tmp;
				//Z
				if (!(ss >> tmp)) throw ParseError("Z-komponentin arvo ep?kelpo " + ss.str());
				v.Z = tmp;
				vertices.push_back(v);
			}
			//Faces
			else if (line[0] == 'f')
			{
				Face face;
				stringstream ss;
				ss << line.substr(2);
				int tmp = 0;
				//1
				if (!(ss >> tmp)) throw ParseError("Ensimm?isen indeksin arvo ep?kelpo " + ss.str());
				face.a = tmp - 1;
				//2
				if (!(ss >> tmp)) throw ParseError("Toisen indeksin arvo ep?kelpo " + ss.str());
				face.b = tmp - 1;
				//3
				if (!(ss >> tmp)) throw ParseError("Kolmannen indeksin arvo ep?kelpo " + ss.str());
				face.c = tmp - 1;

				faces.push_back(face);
			}
			//Name
			else if (line[0] == 'o')
			{
				name = line.substr(2);
			}
			else
			{
				continue;
			}
		}

	}
	void Write(const std::string& path) override
	{
		ofstream file(path);
		if (file.bad() || file.fail())
		{
			throw CannotOpenFileException(path);
		}
		file << "# MeshSimplifier OBJ File\n";
		file << "o " << name << "\n";
		for (Vertex& v : vertices)
		{
			file << "v " << v.X << " " << v.Y << " " << v.Z << "\n";
		}
		for (Face& f : faces)
		{
			file << "f " << f.a + 1 << " " << f.b + 1 << " " << f.c + 1 << "\n";
		}
	}
};