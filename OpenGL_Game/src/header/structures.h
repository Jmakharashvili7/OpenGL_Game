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

struct Vector4
{
	float x, y, z, w;
};

struct Lighting
{
	Vector4 ambient, diffuse, specular;
};

struct Material
{
	Vector4 ambient, diffuse, specular;
	GLfloat shininess;
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


struct TexCoord
{
	GLfloat u, v;
};

struct Mesh
{
	Vertex* vertices;
	Vector3* normals;
	GLushort* indices;
	TexCoord* texCoords;
	int vertexCount, normalCount, indexCount, texCoordCount;	

	Mesh()
	{
		vertices = nullptr;
		normals = nullptr;
		indices = nullptr;

		vertexCount = 0;
		normalCount = 0;
		indexCount = 0;
	}
};
#endif // STRUCTURES_H