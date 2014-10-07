#include<glut.h>

void initializeDrawingGraphics()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the background color
	glColor3f(0.0, 0.0, 0.0);	//Set the drawing color
	glPointSize(9.0f);	//Set the Point Size 4 pixel
	//glMatrixMode(GL_PROJECTION);	
	//glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void drawingDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	//Clear the screen
	//GL_Points primitive
	glPointSize(9.0f);
	glBegin(GL_POINTS);
	glColor3f(0.9, 0.8, 0.0);
	glVertex2i(0, 0);
	glVertex2i(640, 0);
	glVertex2i(0, 478);
	glVertex2i(638, 478);
	glEnd();
	
	//GL_Lines primitive
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	//First Line
	glColor3f(0.9, 0.0, 0.7);
	glVertex2i(20, 10);
	glVertex2i(20, 200);
	//Second Line
	glColor3f(0.4, 0.7, 0.9);
	glVertex2i(630, 10);
	glVertex2i(630, 200);
	//Third Line
	glColor3f(0.8, 0.6, 1);
	glVertex2i(20, 200);
	glVertex2i(50, 200);
	glEnd();

	//GL_Line_Strip
	glLineWidth(4.0);
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex2i(50, 100);
	glVertex2i(200, 100);
	glColor3f(0, 1, 0);
	glVertex2i(200, 200);
	glVertex2i(400, 200);
	glEnd();

	//GL_Line_Loop
	glBegin(GL_LINE_LOOP);
	glVertex2i(50, 220);
	glVertex2i(150, 220);
	glVertex2i(150, 320);
	glVertex2i(250, 320);
	glVertex2i(250, 220);
	glEnd();

	//GL_Triangles
	glLineWidth(5.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	//1st triangle
	glColor3f(0.6, 0.5, 0.9);
	glVertex2i(30, 230);
	glColor3f(0.8, 0, 0.4);
	glVertex2i(130, 230);
	glColor3f(0.8, 0.8, 0);
	glVertex2i(80, 320);

	//2nd triangle
	glVertex2i(260, 230);
	glVertex2i(360, 230);
	glVertex2i(310, 320);
	glEnd();


	//GL_Triangle_Strip
	glPolygonMode(GL_FRONT, GL_FILL);
	glBegin(GL_LINE_STRIP);
	glVertex2i(30, 10);
	glVertex2i(80, 90);
	glVertex2i(130, 10);
	glVertex2i(180, 90);
	glVertex2i(230, 10);
	glEnd();

	glPointSize(6.0);
	glBegin(GL_POINTS);
	glVertex2i(500, 350);	//center point
	glVertex2i(450, 300);	//lower left point
	glVertex2i(550, 300);	//Lower right point
	glVertex2i(550, 400);	//upper right point
	glVertex2i(450, 400);	//upper left point
	

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(500, 350);	//center point
	glColor3f(0.4, 0.0, 0.0);
	glVertex2i(550, 300);	//Lower right point
	glColor3f(0.0, 0.0, 0.2);
	glVertex2i(550, 400);	//upper right point
	glColor3f(0.9, 0.8, 0.5);
	glVertex2i(450, 300);	//lower left point
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(450, 400);	//upper left point	
	glEnd();

	glFlush();
}
void InitializeWindow()
{
	glutInitWindowSize(640, 480);	//Set the window size
	glutInitWindowPosition(100, 100);	//Set the window position on screen
	glutCreateWindow("Lab01");
}
void registerCallBackFunctions()
{
	glutDisplayFunc(drawingDisplay);
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);	//Initialize toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set the display mode
	InitializeWindow();
	registerCallBackFunctions();
	initializeDrawingGraphics();
	glutMainLoop();	//Go into a perpetual loop
}
