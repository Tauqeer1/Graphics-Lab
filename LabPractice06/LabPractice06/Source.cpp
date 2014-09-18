#include<iostream>
#include<glut.h>
#include<math.h>

struct GLPoints
{
	GLfloat x, y;
};

void drawDot(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void initWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//Set the display mode
	glutInitWindowSize(800, 600);	//set the windows size
	glutInitWindowPosition(0, 0);	//Set the initial position of window
	glutCreateWindow("Lab06");
}
void initializeGraphics()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the background color
	glColor3f(0.0f, 0.0f, 0.0f);	//Set the drawing color
	glPointSize(4.0);	//Set the Point Size 4 pixel
	//glMatrixMode(GL_PROJECTION);	
	//glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void sierpinski_render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLPoints T[3] = { { 10, 10 }, { 600, 10 }, { 300, 600 } };
	int index = rand() % 3;
	GLPoints point = T[index];
	drawDot(point.x, point.y);
	for (int i = 0; i < 5; i++)
	{
		index = rand() % 3;
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawDot(point.x, point.y);
	}
	glFlush();
}

void registerCallbacks()
{
	glutDisplayFunc(sierpinski_render);
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);	//Initialize the tool kit
	initWindow();
	registerCallbacks();
	initializeGraphics();
	glutMainLoop();

}