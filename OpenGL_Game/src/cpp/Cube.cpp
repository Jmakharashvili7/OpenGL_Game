#include "Cube.h"

Cube::Cube(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	m_position = { x, y, z };
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	if (m_mesh->vertices != nullptr && m_mesh->colors != nullptr && m_mesh->indices != nullptr)
	{
		glPushMatrix();

		glTranslatef(m_position.x, m_position.y, m_position.z);
		glRotatef(m_rotation, 1.0f, 0.0f, 0.0f);

		glBegin(GL_TRIANGLES);
		for (int i = 0; i < m_mesh->indexCount; i++)
		{
			glColor3fv(&m_mesh->colors[m_mesh->indices[i]].r);
			glVertex3fv(&m_mesh->vertices[m_mesh->indices[i]].x);
		}

		glEnd(); // end of the draw
		glPopMatrix();
	}
}

void Cube::Update()
{
	if (m_mesh->vertices != nullptr && m_mesh->colors != nullptr && m_mesh->indices != nullptr)
	{
		m_rotation += 0.5f;
	}
}
