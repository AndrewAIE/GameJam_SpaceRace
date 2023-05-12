#pragma once
#include "Point2D.h"
#include "raylib.h"

class Paddle
{

public:
	Paddle();
	Paddle(int height, int width, int speed, Vector2 position);
	~Paddle();
	
	void Draw();
	void MoveLeft();
	void MoveRight();
	 
	Vector2 GetPosition();


private:
	Vector2 m_position;
	int m_height;
	int m_width;
	int m_speed;

	


};

