#include<math.h>
#include<glut.h>

#include"supportedClass.h"
#include"Turtle.h"
void drawArc(Point2 centre, float radius, float startAngle, float sweep);
void drawArc(Point2 centre, float radius, float startAngle, float sweep)
{
	Turtle t;
	const int n = 30;
	float angle = startAngle * 3.14159265 / 180;
	float angleInc = sweep * 3.14159265 / (180 * n);
	float cx = centre.getX(), cy = centre.getY();
	t.moveTo(Point2(cx + radius*cos(angle), cy + radius*sin(angle)));
	for (int k = 1; k < n; k++, angle += angleInc)
	{
		t.lineTo(Point2(cx + radius*cos(angle), cy + radius*sin(angle)));
	}
}



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
	glClear(GL_COLOR_BUFFER_BIT);
	Point2 p(200, 200);
	drawArc(p, 20, 500, 500);
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
