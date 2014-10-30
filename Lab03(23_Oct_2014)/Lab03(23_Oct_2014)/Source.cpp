#include<glut.h>
int screenHeight = 480;
int screenWidth = 640;

struct GLintPoint
{
	int x;
	int y;
};
void initializeDrawingGraphics()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the background color
	glColor3f(0.0, 0.0, 0.0);	//Set the drawing color
	glPointSize(4.0f);	//Set the Point Size 4 pixel
	//glMatrixMode(GL_PROJECTION);	
	//glLoadIdentity();
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
}

void drawDot(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void drawingDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	//Clear the screen
	
	glFlush();
}

void InitializeWindow()
{
	glutInitWindowSize(screenWidth, screenHeight);	//Set the window size
	glutInitWindowPosition(100, 100);	//Set the window position on screen
	glutCreateWindow("Lab01");
}
void myMouse(int button,int state,int x,int y)
{
	static GLintPoint corner[2];
	//static double corner1[2];
	static int numCorners = 0;
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			//corner1[numCorners] = x;
			corner[numCorners].x = x;
			//corner1[numCorners] = screenHeight - y;
			corner[numCorners].y = screenHeight - y;
			
			if (++numCorners == 2)
			{
				glRecti(corner[0].x, corner[0].y, corner[1].x, corner[1].y);
				numCorners = 0;
				glFlush();
			}
			
		}
		else if (button == GLUT_RIGHT_BUTTON)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glFlush();
		}
	}
}
void mouseMovement()
{

}
void registerCallBackFunctions()
{
	glutDisplayFunc(drawingDisplay);
	glutMouseFunc(myMouse);
	//glutMotionFunc(mouseMovement);
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
