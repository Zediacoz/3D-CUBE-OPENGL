#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"


#define REFRESHRATE 16

class HelloGL
{
public:

	HelloGL(int argc, char* argv[]);
	~HelloGL();

	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void DrawCube();

	static Vertex vertices[]; 
	static Color colors[];
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];

	void DrawCubeArray();
	void DrawIndexedCube();

	Camera* camera;
	Cube* cube;

	float rotation;

private:

};

