#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	camera = new Camera();
	camera->eye.x = 0.0f;
	camera->eye.y = 0.0f;
	camera->eye.z = 5.0f;
	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;
	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;

	Cube::Load("cube.obj");

	cube = new Cube(0,0,0);

	rotation = 5.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(5, 5);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, 60);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDepthMask(GL_FALSE);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glutMainLoop();
}


HelloGL::~HelloGL()
{

}

void printHUD(float x, float y, const char *text)
{
	// Score
	int textLenght = strlen(text);
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRasterPos2f(x, y);

	// Disabled lightning and texture2d just in case to not have any problems
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	for (int i = 0; i < textLenght; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); 
	}
	
	// Time
	glRasterPos2f(x + 6, y);
	char time[5];
	char timeText[] = "Time: ";
	for (int i = 0; i < strlen(timeText); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, timeText[i]);
	}
	//Elapsed time in char
	itoa(glutGet(GLUT_ELAPSED_TIME)/1000, time, 10);
	for (int i = 0; i < strlen(time); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, time[i]);
	}
	glEnable(GL_TEXTURE_2D);
	
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	printHUD(-4, 3.8 , "Score: ");
	
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	cube->Draw();
	
	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, 
			  camera->center.x, camera->center.y, camera->center.z, 
		      camera->up.x, camera->up.y, camera->up.z);
	cube->Update();
	glutPostRedisplay();

}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		rotation += 2.0f;

	if (key == 'a')
		rotation -= 2.0f;

	if (key == 'q')
		camera->eye.x -= 1.0f;

    if (key == 'e')
		camera->eye.x += 1.0f;

	if (key == 'w')
		camera->eye.y += 1.0f;

	if (key == 's')
		camera->eye.y -= 1.0f;

	if (key == '1')
		camera->eye.z += 1.0f;

	if (key == '2')
		camera->eye.z -= 1.0f;


}
