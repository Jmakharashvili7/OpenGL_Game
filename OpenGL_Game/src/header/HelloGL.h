#pragma once
#ifndef HELLOGL_H
#define HELLOGL_H 

#include <Windows.h> // Required for OpenGL on Windows
#include <gl/GL.h> // OpenGL
#include <gl/GLU.h> // OpenGl Utilities

#include "freeglut.h" // freeglut Library
#include "GLUTCallbacks.h" // Glut call backs
#include "structures.h" // common structs
#include "StaticObjects.h"
#include "Cube.h"
#include "SceneObject.h"
#include "Constants.h"

// definitions for values
#define REFRESHRATE 16

class HelloGL
{
public:
	// Cosntructor Definition 
	HelloGL(int argc, char* argv[]);

	void Update();
	void Display();
	void Keyboard(unsigned char key, int x, int y);

	// init methods
	void InitObjects();
	void InitGL(int argc, char* argv[]);

	// Destructor 
	~HelloGL(void);
private:
	float rotation;
	double cameraX, cameraY, cameraZ;
	SceneObject* sceneObjects[CUBECOUNT + PYRAMIDCOUNT];
	Camera* camera;
};
#endif // HELLOGL_H