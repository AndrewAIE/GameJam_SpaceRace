#pragma once
#include "raylib.h"
#include "Point2D.h"

class Ball
{
public:
	
	Ball();
	Ball(int width, int height, float speed, Vector2 position, Vector2 direction, Color color);
	~Ball();
	
	void Draw();
	void Update();
	void Move();

	void CheckCollision(Rectangle object);

	Rectangle GetBoundBox();
	

private:

	int m_width;
	int m_height;
	float m_speed;

	Vector2 m_position;
	Vector2 m_direction;

	Rectangle m_rectangleBound;

	Color m_color;

	
	

};

