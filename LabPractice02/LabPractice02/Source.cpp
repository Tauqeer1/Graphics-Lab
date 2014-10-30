#include<glut.h>
#include<math.h>

#include"Point.h"
#include"turtle.h"

#define M_PI       3.14159265358979323846

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

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the background color
	glColor3f(0.0f, 0.0f, 0.0f);	//Set the drawing color
	glLineWidth(4.0f);	//Set the line width
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);	
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	//Clear the screen
	glColor3f(1.0, 0.0, 0.0);
	Point2 p(200, 200);
	drawArc(p, 100, 0, 400);

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

