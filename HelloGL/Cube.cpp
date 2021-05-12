#include "Cube.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Vertex* Cube::indexedVertices = nullptr;
Color* Cube::indexedColors = nullptr;
GLushort* Cube::indices = nullptr;

int Cube::numVertices = 0;
int Cube::numColours = 0;
int Cube::numIndices = 0;


Cube::Cube(float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 0;
}


Cube::~Cube(void)
{
	
}

void Cube::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);

	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	glRotatef(_rotation* 2.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(_rotation / 2.0f, 0.0f, 0.0f, 1.0f);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}
void Cube::Update()
{
	_rotation += 0.1f;
	if (_rotation >= 360.0f)
		_rotation = 0.0f;
}

bool Cube::Load(char* path)
{
	ifstream inFile;

	inFile.open(path);

	if (!inFile.good()) 
	{ 
		cerr << "Can't open texture file " << path << endl; 
	    return false;
	}

	inFile >> numVertices;

	indexedVertices = new Vertex[numVertices];

	for (int i = 0; i < numVertices; i++)
	{ 
		inFile >> indexedVertices[i].x;
		inFile >> indexedVertices[i].y;
		inFile >> indexedVertices[i].z;
	}

	inFile >> numColours;

	indexedColors = new Color[numColours];

	for (int i = 0; i < numColours; i++)
	{
		inFile >> indexedColors[i].r;
		inFile >> indexedColors[i].g;
		inFile >> indexedColors[i].b;
	}

	inFile >> numIndices;

	indices = new GLushort[numIndices];
								
	for (int i = 0; i < numIndices; i++)
	{
		inFile >> indices[i];
	}
	
		inFile.close();

		return true;
}