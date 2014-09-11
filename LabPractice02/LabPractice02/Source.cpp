#include<glut.h>

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the background color
	glColor3f(0.0f, 0.0f, 0.0f);	//Set the drawing color
	glLineWidth(4.0f);	//Set the line width
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);	
}
void drawLine(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
	glVertex2i(x1, y1);		//x1,y1
	glVertex2i(x2, y2);	//x2,y2
	glEnd();
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	//Clear the screen
	drawLine(50, 90, 50, 190);
	glFlush();	//Send to the output screen from buffer

}
void main(int argc,char **argv)
{
	glutInit(&argc, argv);	//Initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//Set the display mode
	glutInitWindowSize(640, 480);	//Set the window size
	glutInitWindowPosition(10, 40);	//Set the window position on screen
	glutCreateWindow("Lab02");	//Create the window


	//Register call back function
	glutDisplayFunc(myDisplay);

	myInit();
	glutMainLoop();
}