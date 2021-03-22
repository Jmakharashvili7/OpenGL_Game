#include "HelloGL.h"
#include "MeshLoader.h"
#include "Texture2D.h"
#include <iostream>

HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(argc, argv);
	InitObjects();
	glutMainLoop();
}

HelloGL::~HelloGL()
{
	delete camera;
}

void HelloGL::Update()
{
	// Reset Model View Matrix
	glLoadIdentity();
	gluLookAt(camera->eye.x + cameraX, camera->eye.y + cameraY, camera->eye.z, camera->center.x + cameraX, camera->center.y + cameraY,
				camera->center.z, camera->up.x, camera->up.y, camera->up.z);

	// Move the object back on z axis
	glTranslatef(0.0f, -0.0f, -5.0f);

	// Reset the rotation 
	glutPostRedisplay();
	if (rotation >= 360.0f)
		rotation = 0.0f;

	for (int i = 0; i < CUBECOUNT; i++)
	{
		sceneObjects[i]->Update();
	}
}

void HelloGL::InitObjects()
{
	// initialize the variables
	rotation = 0.0f;

	// initialize the camera
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	// Load the cube mesh
	Mesh* cubeMesh = MeshLoader::Load("files/cube.txt");

	// Load the texture for the cube
	Texture2D* texture = new Texture2D();
	texture->Load("textures/Penguins.raw", 512, 512);

	// setup cube
	for (int i = 0; i < CUBECOUNT; i++)
	{
		sceneObjects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

	/* removed pyramid load methods
	Mesh* pyramidMesh = MeshLoader::Load("files/pyramid.txt");
	for (int i = CUBECOUNT; i < PYRAMIDCOUNT; i++)
	{
		sceneObjects[i] = new StaticObject(pyramidMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}


	for (int i = CUBECOUNT; i < PYRAMIDCOUNT; i++)
	{
		sceneObjects[i]->Draw();
	}*/
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	// Window Settings
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	// Functions
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	// Matrix mode
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the viewport to be the entire window 
	glViewport(0, 0, 800, 800);
	// Set the correct perspective 
	gluPerspective(45, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	// face culling
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the screen

	for (int i = 0; i < CUBECOUNT; i++)
	{
		sceneObjects[i]->Draw();
	}

	glFlush(); // flush the scene to the buffer
	glutSwapBuffers(); // swap the buffers 
}   

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		cameraX += 0.1;
	else if (key == 'a')
		cameraX -= 0.1;
	else if (key == 'w')
		cameraY += 0.1;
	else if (key == 's')
		cameraY -= 0.1;
}

