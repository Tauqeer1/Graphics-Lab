#include<iostream>
#include<stdlib.h>
#include<glut.h>
#include"RGBA.h"
#include"Mario.h"

Mario m(Point2(0, 0));

void pressKeySpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		m.changePosition(-20, 0);
		m.changeMode(Mario::RUN);
		break;
	case GLUT_KEY_RIGHT:
		m.changePosition(20, 0);
		m.changeMode(Mario::RUN);
		break;
	case GLUT_KEY_UP:
		if (m.pos_Y < 12)
		{
			m.changePosition(4, 5);
		}
		m.changeMode(Mario::JUMP);
		break;

	case GLUT_KEY_DOWN:
		break;

	default:
		break;
	}
	glutPostRedisplay();
}
void releaseKeySpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
	case GLUT_KEY_UP:
		if (m.pos_Y != 0)
		{
			m.setPosition(m.pos_X, 0);
			m.changeMode(Mario::STAY);
		}
		
		break;

	case GLUT_KEY_DOWN:
		break;

	default:
		break;
	}
	glutPostRedisplay();
}
void initializeDrawingGraphics()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	//Set the background color
	glColor3f(0.0, 0.0, 0.0);	//Set the drawing color
	glPointSize(9.0f);	//Set the Point Size 4 pixel
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_EQUAL, 1.0);


	m.changeMode(Mario::STAY);
}

void drawingDisplay()
{
	//glClear(GL_COLOR_BUFFER_BIT);	//Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m.render();
	glFlush();
	
	glFlush();

}
void InitializeWindow()
{
	glutInitWindowSize(640,480 );	//Set the window size
	glutInitWindowPosition(100, 100);	//Set the window position on screen
	glutCreateWindow("Mario");
}
void registerCallBackFunctions()
{
	glutDisplayFunc(drawingDisplay);

	glutSpecialFunc(pressKeySpecial);
	glutSpecialUpFunc(releaseKeySpecial);
	//glutKeyboardFunc(myKB_Handler);
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
