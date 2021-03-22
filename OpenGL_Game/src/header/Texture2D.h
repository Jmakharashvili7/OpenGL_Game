#pragma once
#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <Windows.h> // Required for OpenGL on Windows
#include <gl/GL.h> // OpenGL
#include <gl/GLU.h> // OpenGl Utilities
#include <iostream> 

#include "freeglut.h" // freeglut Library

class Texture2D
{
private:
	GLuint m_ID; // texture ID
	int m_width, m_height;
public:
	Texture2D();
	~Texture2D();

	bool Load(std::string path, int width, int height);

	GLuint GetID() const { return m_ID; }
	int GetWidth() const { return m_width; }
	int GetHeight() const { return m_height; }
};
#endif // TEXTURE2D_H

