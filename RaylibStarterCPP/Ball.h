#pragma once
#include "raylib.h"
#include "Point2D.h"

class Ball
{
public:
	
	Ball();
	Ball(int radius, Vector2 speed, Vector2 position, Color color);
	~Ball();
	
	void Draw();
	void Update();
	void Move();

private:

	int m_radius;
	
	Color m_color;

	Vector2 m_position;
	Vector2 m_speed;
	

};

