#include<glut.h>
void initialize()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the background color
	glColor3f(0.0f, 0.0f, 0.0f);	//Set the base brush color
	glLineWidth(3.0);	//Set the line width
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void drawSquare(int x1, int y1, int x2, int y2)
{
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1, y1);
	glVertex2i(x2, y1);
	glVertex2i(x2, y2);
	glVertex2i(x1, y2);
	glEnd();
}
void drawTriangle(int x1, int y1, int x2, int y2, int x3)
{
	glColor3f(0.4, 0.8, 0.7);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1, y1);
	glVertex2i(x2, y1);
	glVertex2i(x3, y2);
	glEnd();

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawSquare(150, 350, 250, 450);	//Calling Draw function
	drawTriangle(30, 350, 130, 230, 50);
	glFlush();
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);	//Initialize toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//Set the display mode
	glutInitWindowSize(640, 480);	//Set the window size
	glutInitWindowPosition(10, 50);		//set the window position
	glutCreateWindow("Lab04");	//Create window and set the name

	//Register Callback functions
	glutDisplayFunc(display);


	initialize();
	glutMainLoop();
}

