
#ifndef TURTLE_H
#define	TURTLE_H

#pragma once

class Turtle
{
private:
	Point2 CP;
	float CD;

public:
	Turtle()
	{

	}
	Turtle(Point2 p, float angle)
	{
		CP.set(p.getX(), p.getY());
		CD = angle;
	}
	void moveTo(Point2 p)
	{ 
		CP.set(p.getX(), p.getY()); 
	}

	void lineTo(Point2 newp)
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
			lineTo(Point2(x, y));
		else
			moveTo(Point2(x, y));
	}
};

#endif	/* TURTLE_H */

