#pragma once
#include "Point2D.h"
#include "raylib.h"

class Brick
{
public:
	Brick();
	Brick(int height, int width, Vector2 position);
	~Brick();
	
	void Draw();
	void AssignColor(int yPos);
	void CheckCollision(Rectangle ball);
	
	Rectangle GetBoundBox();


private:
	
	int m_height;
	int m_width;
	int m_offset;
		
	Color m_color;
	Vector2 m_position;

	Rectangle m_rectangleBound;

};

