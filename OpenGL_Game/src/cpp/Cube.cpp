#include "Cube.h"
#include "Texture2D.h"

Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	m_position = { x, y, z };
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	if (m_mesh->vertices != nullptr && m_mesh->normals != nullptr && m_mesh->indices != nullptr)
	{
		// bind the texture to the ID
		glBindTexture(GL_TEXTURE_2D, m_texture->GetID());

		// enable texture2D
		glEnable(GL_TEXTURE_2D);

		// enable the states and pass in the arrays for colors, vertices, and texture locations
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, m_mesh->vertices);
		glNormalPointer(GL_FLOAT, 0, m_mesh->normals);
		glTexCoordPointer(2, GL_FLOAT, 0, m_mesh->texCoords);

		glPushMatrix();
		
		// translate the cube
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glRotatef(m_rotation, 1.0f, 0.0f, 0.0f);

		// draw the cube
		glDrawElements(GL_TRIANGLES, m_mesh->indexCount, GL_UNSIGNED_SHORT, m_mesh->indices);

		glPopMatrix();

		// disable the clients 
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Cube::Update()
{
	if (m_mesh->vertices != nullptr && m_mesh->normals != nullptr && m_mesh->indices != nullptr)
	{
		m_rotation += 0.5f;
	}
}
