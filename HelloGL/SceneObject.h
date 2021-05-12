#pragma once

class Cube : public SceneObject
{
private:
	Vector3 _position;
	GLfloat _rotation;
	GLfloat _rotationValue;
	GLfloat _zMovement;
public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube(void);
	void Draw();
	void Update();
};