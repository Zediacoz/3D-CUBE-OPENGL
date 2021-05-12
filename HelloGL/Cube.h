#pragma once
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include "Structures.h"

class Cube
{

private:

	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColours, numIndices;

	Vector3 _position;
	GLfloat _rotation;

public:

	Cube(float x, float y, float z);
	~Cube(void);

	void Draw();
	void Update();

	static bool Load(char* path);

};