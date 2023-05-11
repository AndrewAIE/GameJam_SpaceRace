#pragma once
#include "Point2D.h"
class Paddle
{

public:
	Paddle();
	Paddle(int height, int width, int x, int y, int speed);
	~Paddle();
	
	void Draw();
	void MoveLeft();
	void MoveRight();
	void SetPosition(Point2D position);
	Point2D GetPosition();


private:
	Point2D m_position;
	int m_height;
	int m_width;
	int m_speed;

	


};

