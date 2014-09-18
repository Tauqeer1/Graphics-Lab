#include<glut.h>
#include<math.h>
void myDisplay()
{

}
void initWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set the display mode
	glutInitWindowSize(1366, 700);	//Set the window size
	glutInitWindowPosition(0, 0);	//Set the window position
	glutCreateWindow("2d Project");	//name the window title and create window
}
void drawingDisplay()
{
	float x, y;
	int radius = 20;
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Sun
	glBegin(GL_POLYGON);
	glColor3ub(240, 238, 29);
	for (float i = 0; i < 360.0; i++)
	{
		y = radius*sin(i);
		x = radius*cos(i);
		glVertex2f(x + 105, y + 270);
	}
	glEnd();

	//Mountain
	glBegin(GL_TRIANGLES);
	glColor3ub(181, 122, 18);
	glVertex2d(-20, 230);
	glVertex2d(60, 230);
	glVertex2d(20, 350);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(181, 122, 18);
	glVertex2d(50, 230);
	glVertex2d(110, 230);
	glVertex2d(80, 350);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(181, 122, 18);
	glVertex2d(100, 230);
	glVertex2d(160, 230);
	glVertex2d(130, 350);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(181, 122, 18);
	glVertex2d(150, 230);
	glVertex2d(210, 230);
	glVertex2d(180, 350);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(181, 122, 18);
	glVertex2d(200, 230);
	glVertex2d(260, 230);
	glVertex2d(230, 350);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3ub(181, 122, 18);
	glVertex2d(250, 230);
	glVertex2d(310, 230);
	glVertex2d(280, 350);
	glEnd();

	
	glFlush();	//Send to display
}
void registerCallback()
{
	glutDisplayFunc(drawingDisplay);
}

void initializeGraphics()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);	//Set the bacground color
	glColor3f(0, 0, 0);	//Set the base drawing color
	glPointSize(4.0);	//Set the point size in pixels
	glLineWidth(2.0);	//Set the line width
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();
	gluOrtho2D(0, 300, 0, 400);
	glViewport(0, 0, 639, 479);
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