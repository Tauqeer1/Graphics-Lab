#include<glut.h>
void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the background color
	glColor3f(0.0f, 0.0f, 0.0f);	//Set the base drawing color
	glLineWidth(5.0);	//Set the line width
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void drawTriangle(int x1, int y1, int x2, int y2, int x3)
{
	glColor3f(0.5f, 0.8f, 0.9f);	//Set the color
	glBegin(GL_LINE_STRIP);	
	glVertex2i(x1, y1);
	glVertex2i(x2, y1);
	glVertex2i(x3, y2);
	glVertex2i(x1, y1);
	glEnd();
}
void drawSquare(int x1, int y1, int x2, int y2)
{
	glColor3f(1.0, 0.7, 0.3);
	glBegin(GL_LINE_STRIP);
	glVertex2i(x1, y1);	//x1,y1
	glVertex2i(x2, y1);	//x2,y1
	glVertex2i(x2, y2);	//x2,y2
	glVertex2i(x1, y2);	//x1,y2
	glVertex2i(x1, y1);	//x1,y1
	glEnd();
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	//Clear the screen and set color		
	drawTriangle(20, 350, 120, 400, 70);	//Calling triangle function
	drawSquare(150, 350, 250, 450);		//Calling Square function
	glFlush();	//Send to the screen

}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);	//Initialize toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//Set display mode
	glutInitWindowSize(640, 480);	//Set the window Size
	glutInitWindowPosition(10, 50);	//Set the window Position on Screen
	glutCreateWindow("Lab03");	//Create window and set the window name

	//Register Call back
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}