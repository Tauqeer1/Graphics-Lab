#include<glut.h>

void initialize()
{
	glClearColor(0.8f, 0.9f, 0.8f, 1.0f);	//Set the background color
	glColor3f(0.0f, 0.0f, 0.0f);	//Set the base drawing color
	glLineWidth(3.0);	//Set the width of drawing pointer
	gluOrtho2D(640.0, 0.0, 480.0, 0.0);
}
void drawSquarePolygon(int x1, int y1, int x2, int y2)
{
	glColor3f(0.6f, 0.6f, 0.6f);
	glBegin(GL_POLYGON);
	glVertex2i(x1, y1);
	glVertex2i(x2, y1);
	glVertex2i(x2, y2);
	glVertex2i(x1, y2);
	glEnd();
}
void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);	//Clear the screen and set the new color
	drawSquarePolygon(100, 100, 200, 200);
	glFlush();
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);	//Initialize toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set the display mode
	glutInitWindowSize(640, 480);	//Set the window size
	glutInitWindowPosition(10, 50);	//set the window postion on screen
	glutCreateWindow("Lab05");	//create the window and set the title
	

	//Register callback functions
	glutDisplayFunc(display);
	
	initialize();
	glutMainLoop();
}