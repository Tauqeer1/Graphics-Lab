#include<glut.h>

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the background color
	glColor3f(0.0f, 0.0f, 0.0f);	//Set the drawing color
	glPointSize(4.0f);	//Set the Point Size 4 pixel
	//glMatrixMode(GL_PROJECTION);	
	//glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	//Clear the screen
	//Command for drawing Points(primitives)
	glBegin(GL_POINTS);
	glVertex2i(100, 50);
	glVertex2i(100, 130);
	glVertex2i(150, 130);
	glEnd();
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);	//Initialize toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set the display mode
	glutInitWindowSize(640, 480);	//Set the window size
	glutInitWindowPosition(100, 100);	//Set the window position on screen
	glutCreateWindow("Lab01");

	//register call back function
	glutDisplayFunc(myDisplay);

	myInit();
	glutMainLoop();	//Go into a perpetual loop
}
