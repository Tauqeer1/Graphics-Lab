#include<glut.h>
#include<math.h>

class Point
{

public:
	Point()
	{
		x = y = 0.0;
	} // constructor 1

	Point(float xx, float yy)
	{
		x = xx;
		y = yy;
	} // constructor 2

	void set(float xx, float yy)
	{
		x = xx;
		y = yy;
	}
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
	void draw(void)
	{
		//glPointSize(0.0);
		/*
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
		glEnable(GL_POINT_SMOOTH);
		*/
		glBegin(GL_POINTS); // draw this point
		glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();

		//glDisable(GL_POINT_SMOOTH);

	}// end draw
private:
	float x, y;

};
class Turtle
{
private:
	Point CP;
	float CD;

public:
	Turtle()
	{

	}
	Turtle(Point p, float angle)
	{
		CP.set(p.getX(), p.getY());
		CD = angle;
	}
	void moveTo(Point p)
	{
		CP.set(p.getX(), p.getY());
	}

	void lineTo(Point newp)
	{
		glBegin(GL_LINES);
		glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
		glVertex2f((GLfloat)newp.getX(), (GLfloat)newp.getY()); // draw the line
		glEnd();

		CP.set(newp.getX(), newp.getY()); // update the CP
	}

	void turnTo(float angle)
	{
		CD = angle;
	}
	void turn(float angle)
	{
		CD += angle;
	} //Use a negative argument to make a right turn.

	void forward(float dist, int isVisible)
	{
		const float RadPerDeg = 0.017453393; //radians per degree
		float x = CP.getX() + dist * cos(RadPerDeg * CD);
		float y = CP.getY() + dist * sin(RadPerDeg * CD);
		if (isVisible)
			lineTo(Point(x, y));
		else
			moveTo(Point(x, y));
	}
};
#define M_PI       3.14159265358979323846
void drawArc(Point centre, float radius, float startAngle, float sweep);
void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the background color
	glColor3f(0.0f, 0.0f, 0.0f);	//Set the base drawing color
	glLineWidth(5.0);	//Set the line width
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void drawArc(Point centre, float radius, float startAngle, float sweep)
{
	Turtle t;
	const int n = 30;
	float angle = startAngle * M_PI / 180; //convert to radian
	float angleInc = sweep * M_PI / (180 * n);
	float cx = centre.getX(), cy = centre.getY();	//200,200
	float a, b;
	a = cx + radius*cos(angle);
	b = cy + radius*sin(angle);
	t.moveTo(Point(a, b));
	for (int k = 1; k < n; k++, angle += angleInc)
	{
		t.lineTo(Point(cx + radius*cos(angle), cy + radius*sin(angle)));
	}
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	//Clear the screen and set color
	glColor3f(1.0, 0.0, 0.0);
	Point p(200, 200);
	drawArc(p, 100, 0, 400);
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



