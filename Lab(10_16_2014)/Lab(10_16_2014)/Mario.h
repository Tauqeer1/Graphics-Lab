#pragma once

class Point2
{
  public:
    Point2() { x = y = 0.0f;} // constructor 1
    Point2(float xx,float yy) { x = xx; y = yy;} // constructor 2
    void set(float xx,float yy) { x = xx; y = yy;} 
    float getX() { return x;}
    float getY() { return y;}
    void draw(void) 
    { 
		glPointSize(2.0);
		
		glEnable( GL_BLEND);
  		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  		glHint( GL_POINT_SMOOTH_HINT, GL_NICEST); 
 		glEnable( GL_POINT_SMOOTH);

		glBegin(GL_POINTS); // draw this point
			glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();

		glDisable( GL_POINT_SMOOTH);

    }// end draw
  private:
    float x, y;
}; // end class Point2




class Mario
{
public:
	
	RGBApixmap pix[5]; // make six empty pixmaps, one for each side of cube
	enum State	{	STANDING,	RUNNING1, RUNNING2,	RUNNING3,JUMPING,	DIE	}state ;
	enum ModeType{	STAY,RUN,	R,	JUMP,	DEAD} mode;
    float pos_X, pos_Y;
   
	Mario(Point2 pos)
		
	{
		pix[0].readBMPFile("MarioStanding.bmp");
		pix[1].readBMPFile("MarioRun2.bmp");
		pix[2].readBMPFile("MarioRun1.bmp");
		pix[3].readBMPFile("MarioRun1.bmp");
		pix[4].readBMPFile("MarioJump.bmp");

		for (int i = 0; i < 5; i++){
			pix[i].setChromaKey(192, 192, 192);

		}
		this->pos_X = pos.getX();
		this->pos_Y = pos.getY();
  
 
	};
	
	void setPosition(float x, float y)
	{
		this->pos_X = x;
		this->pos_Y = y;
	}
	void render();
	void changeMode(ModeType m);
	void run();
	void die();
	void stay();
	void jump();
	
	void changePosition(float dx, float dy)
	{
		
	}

};

void Mario::render()
{
  //glRasterPos2i(this->pos_X,this->pos_Y);
  //pix[0].mDraw();

  switch (mode)
  {
  case STAY:
	  glRasterPos2i(this->pos_X, this->pos_Y);
	  pix[0].mDraw();
	  break;

  case RUN:
	  run();
	  break;

  case JUMP:
	  break;


  }

}


void Mario::run()
{

	switch (state)
	{
	case RUNNING1:
		state = RUNNING2;
		break;
	case RUNNING2:
		state = RUNNING3;
		break;
	case RUNNING3:
		state = RUNNING1;
		break;
	}
	changePosition(20, 0);
	glRasterPos2i(this->pos_X, this->pos_Y);
	pix[state].mDraw();
}




void Mario::changeMode(ModeType m)
{
	if (mode == m){
		return;
	}
	switch (m)
	{
	case STAY:
		state = STANDING;
		break;
	case RUN:
		state = RUNNING1;
		break;
	
	case JUMP:
		state = JUMPING;
		break;
	}
	mode = m;
}