#include<glut.h>
#include<math.h>
void initWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set the display mode
	glutInitWindowSize(630, 480);	//Set the window size
	glutInitWindowPosition(0, 0);	//Set the window position
	glutCreateWindow("Lab08");	//name the window title and create window
}
void drawingDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_QUADS);

	glVertex2i(200, 200);
	glVertex2i(400, 200);
	glVertex2i(400, 600);
	glVertex2i(200, 600);
	glEnd();

	glFlush();

}
void registerCallback()
{
	glutDisplayFunc(drawingDisplay);
}

void initializeGraphics()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the bacground color
	glColor3f(0, 0, 0);	//Set the base drawing color
	glPointSize(4.0);	//Set the point size in pixels
	glLineWidth(2.0);	//Set the line width
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	gluOrtho2D(0, 630, 0, 480);
	//glViewport(0, 0, 639, 479);
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);	//Initialize toolkit
	initWindow();
	//Register call back function
	registerCallback();
	initializeGraphics();
	glutMainLoop();
}