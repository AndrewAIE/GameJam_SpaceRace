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
	


private:
	
	int m_height;
	int m_width;
	int m_offset;
		
	Color m_color;
	Vector2 m_position;


};

