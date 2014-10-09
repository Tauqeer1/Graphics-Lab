#include<math.h>
#include<glut.h>

#include"supportedClass.h"
#include"Turtle.h"
#define M_PI       3.14159265358979323846
void drawArc(Point2 centre, float radius, float startAngle, float sweep);
void drawArc(Point2 centre, float radius, float startAngle, float sweep)
{
	Turtle t;
	const int n = 30;
	float angle = startAngle * M_PI / 180;
	float angleInc = sweep * M_PI / (180 * n);
	float cx = centre.getX(), cy = centre.getY();
	t.moveTo(Point2(cx + radius*cos(angle), cy + radius*sin(angle)));
	for (int k = 1; k < n; k++, angle += angleInc)
	{
		t.lineTo(Point2(cx + radius*cos(angle), cy + radius*sin(angle)));
	}
}
void ngon(int n, double cx, double cy, double radius, double rotAngle)
{
	Turtle t;
	if (n < 3)
	{
		return;
	}
	double angle = rotAngle* M_PI / 180;
	double angleInc = 2 * M_PI / n;
	t.moveTo(Point2(radius * cos(angle) + cx, radius*sin(angle) + cy));
	for (int k = 0; k < n; k++)
	{
		angle += angleInc;
		t.lineTo(Point2(radius*cos(angle) + cx, radius*sin(angle) + cy));
	}
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	Point2 p(50, 50);
	drawArc(p, 50, 0, 90);
	glColor3f(1.0, 0.6, 0.0);
	ngon(4, 150, 200, 50, 0.0);
	ngon(4, 20, 200, 50, 0.0);
	ngon(4, 60, 200, 50, 0.0);
	
	
	glFlush();
}


void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the background color
	glColor3f(0.0f, 0.0f, 0.0f);	//Set the drawing color
	glPointSize(4.0f);	//Set the Point Size 4 pixel
	//glMatrixMode(GL_PROJECTION);	
	//glLoadIdentity();
	gluOrtho2D(0.0, 840.0, 0.0, 680.0);
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);	//Initialize toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set the display mode
	glutInitWindowSize(840, 680);	//Set the window size
	glutInitWindowPosition(10, 20);	//Set the window position on screen
	glutCreateWindow("Lab01");

	//register call back function
	glutDisplayFunc(myDisplay);

	myInit();
	glutMainLoop();	//Go into a perpetual loop
}
