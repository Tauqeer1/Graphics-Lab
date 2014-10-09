#include<glut.h>

void initializeDrawingGraphics()
{
	glClearColor(0.4, 1.0, 0.6, 1.0);	//Set the background color
	glColor3f(0.0, 0.0, 0.0);	//Set the drawing color
	glPointSize(9.0f);	//Set the Point Size 4 pixel
	//glMatrixMode(GL_PROJECTION);	
	//glLoadIdentity();
	gluOrtho2D(0.0, 1400.0, 0.0, 700.0);
}

void drawingDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	//Clear the screen

	//House Roof
	glBegin(GL_QUADS);

	glColor3f(0.5, 0, 0.1);
	glVertex2i(400, 550);	//upper left
	glColor3f(0.7, 0.4, 0.2);
	glVertex2i(1000, 550);	//upper right
	glVertex2i(1100, 400);	//lower right
	glVertex2i(300, 400);	//lower left
	glEnd();

	//Roof edge
	glColor3f(0.0, 0.0, 0.0);
	glRecti(300, 400, 1100, 390);

	//House bottom
	glColor3f(0.8, 0.4, 0.2);
	glRecti(350, 390, 1050, 50);

	//Roof lines
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	for (GLint x1 = 400, x2 = 300; x1 <= 600, x2 <= 600; x1 += 20, x2 += 20)
	{
		glVertex2i(x1, 550);
		glVertex2i(x2, 400);
	}
	for (GLint x1 = 1000, x2 = 1100; x1 >= 750, x2 >= 750; x1 -= 20, x2 -= 20)
	{
		glVertex2i(x1, 550);
		glVertex2i(x2, 400);
	}

	for (GLint x1 = 400, y1 = 550, x2 = 1000, y2 = 550; x1 > 300, y1 > 400, x2 > 1000, y2 > 400; x1 -= 7, y1 -= 10, x2 += 7, y2 -= 10)
	{
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
	}
	glEnd();




	//House tower
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.9, 0.5);
	glVertex2i(570, 50);
	glVertex2i(570, 475);
	glVertex2i(700, 650);
	glVertex2i(830, 475);
	glVertex2i(830, 50);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(570, 455);
	glVertex2i(550, 455);
	glVertex2i(550, 475);
	glVertex2i(700, 670);
	glVertex2i(850, 475);
	glVertex2i(850, 455);
	glVertex2i(830, 455);
	glEnd();


	glBegin(GL_QUADS);
	//house tower upper Left window
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(640, 540);
	glVertex2i(595, 480);
	glVertex2i(595, 350);
	glVertex2i(640, 350);

	//house tower upper left inner window
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(635, 525);
	glVertex2i(600, 480);
	glVertex2i(600, 355);
	glVertex2i(635, 355);

	//house tower upper Right window
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(760, 540);
	glVertex2i(805, 480);
	glVertex2i(805, 350);
	glVertex2i(760, 350);

	//house tower upper right inner window
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(765, 525);
	glVertex2i(800, 480);
	glVertex2i(800, 355);
	glVertex2i(765, 355);
	glEnd();

	//house tower upper middle window
	glColor3f(1.0, 1.0, 1.0);
	glRecti(650, 550, 750, 350);	//x1,y1,x2,y2
	//house tower upper middle inner window
	glColor3f(0.0, 0.0, 0.0);
	glRecti(655, 545, 745, 355);

	//house tower door
	glColor3f(1.0, 1.0, 1.0);
	glRecti(650, 250, 750, 50);
	glColor3f(0.0, 0.0, 0.0);
	glRecti(655, 245, 745, 50);
	glColor3f(1.0, 0.0, 0.0);
	glRecti(655, 245, 745, 230);
	glRecti(660, 150, 670, 130);
	glBegin(GL_LINES);
	glVertex2i(675, 230);
	glVertex2i(675, 50);
	glVertex2i(695, 230);
	glVertex2i(695, 50);
	glVertex2i(715, 230);
	glVertex2i(715, 50);
	glVertex2i(735, 230);
	glVertex2i(735, 50);
	glEnd();

	//house tower lower left window
	glColor3f(1.0, 1.0, 1.0);
	glRecti(595, 250, 640, 150);
	//house tower lower left inner window
	glColor3f(0.0, 0.0, 0.0);
	glRecti(600, 245, 635, 155);

	//house tower lower right window
	glColor3f(1.0, 1.0, 1.0);
	glRecti(760, 250, 805, 150);
	//house tower lower right inner window
	glColor3f(0.0, 0.0, 0.0);
	glRecti(765, 245, 800, 155);

	//House left window
	glColor3f(1.0, 1.0, 1.0);
	glRecti(410, 250, 510, 150);
	//house left inner window
	glColor3f(0.0, 0.0, 0.0);
	glRecti(415, 245, 505, 155);

	//house right window
	glColor3f(1.0, 1.0, 1.0);
	glRecti(890, 250, 990, 150);
	//house right inner window
	glColor3f(0.0, 0.0, 0.0);
	glRecti(895, 245, 985, 155);

	glPointSize(5.0);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	//tower upper middle window
	glColor3f(1.0, 1.0, 1.0);
	//vertical line
	glVertex2i(700, 545);
	glVertex2i(700, 355);

	//horizontal line
	glVertex2i(655, 418);
	glVertex2i(745, 418);
	//horizontal  line
	glVertex2i(655, 481);
	glVertex2i(745, 481);

	//tower upper left window
	//vertical line
	glVertex2i(618, 355);
	glVertex2i(618, 505);

	//horizontal line
	glVertex2i(600, 418);
	glVertex2i(635, 418);

	//horizontal line
	glVertex2i(600, 481);
	glVertex2i(635, 481);


	//tower upper right window
	//vertical line
	glVertex2i(783, 355);
	glVertex2i(783, 505);

	//horizontal line
	glVertex2i(765, 418);
	glVertex2i(800, 418);

	//horizontal line
	glVertex2i(765, 481);
	glVertex2i(800, 481);

	//tower lower left window
	//vertical line
	glVertex2i(618, 245);
	glVertex2i(618, 155);
	//horizontal line
	glVertex2i(600, 200);
	glVertex2i(635, 200);

	//tower lower right window
	//vertical line
	glVertex2i(783, 245);
	glVertex2i(783, 155);
	//horizontal line
	glVertex2i(765, 200);
	glVertex2i(800, 200);

	//left window
	//horizontal line
	glVertex2i(415, 200);
	glVertex2i(505, 200);
	//vertical line
	glVertex2i(460, 245);
	glVertex2i(460, 155);

	//right window
	//vertical line
	glVertex2i(940, 155);
	glVertex2i(940, 245);
	//horizontal line
	glVertex2i(895, 200);
	glVertex2i(985, 200);
	glEnd();

	glFlush();

}
void InitializeWindow()
{
	glutInitWindowSize(1400, 700);	//Set the window size
	glutInitWindowPosition(0, 0);	//Set the window position on screen
	glutCreateWindow("2d Scene");
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
