#include<glut.h>
#include<math.h>
void initWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set the display mode
	glutInitWindowSize(1355, 700);	//Set the window size
	glutInitWindowPosition(0, 0);	//Set the window position
	glutCreateWindow("2d Project");	//name the window title and create window
}
void drawingDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRecti(0, 250, 1355, 450);

	glFlush();
}
void registerCallback()
{
	glutDisplayFunc(drawingDisplay);
}

void initializeGraphics()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);	//Set the bacground color
	glColor3f(0.6, 0.6, 0.6);	//Set the base drawing color
	glPointSize(4.0);	//Set the point size in pixels
	glLineWidth(2.0);	//Set the line width
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();
	gluOrtho2D(0, 1355, 0, 700);
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