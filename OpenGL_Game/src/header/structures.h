#pragma once
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

struct Vector3 
{ 
	float x, y, z;
};

struct Camera 
{ 
	Vector3 eye, center, up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

struct Mesh
{
	Vertex* vertices;
	Color* colors;
	GLushort* indices;
	int vertexCount, colorCount, indexCount;	

	Mesh()
	{
		vertices = nullptr;
		colors = nullptr;
		indices = nullptr;

		vertexCount = 0;
		colorCount = 0;
		indexCount = 0;
	}
};
#endif // STRUCTURES_H