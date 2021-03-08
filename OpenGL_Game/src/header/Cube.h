#pragma once
#ifndef CUBE_H
#define CUBE_H

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <fstream>
#include <iostream>

#include "SceneObject.h"
#include "freeglut.h"
#include "structures.h"

class Cube : public SceneObject
{
private:
	GLfloat m_rotation;
	Vector3 m_position;
public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};	
#endif // CUBE_H

