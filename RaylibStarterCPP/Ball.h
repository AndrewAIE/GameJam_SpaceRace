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
	void EdgeCollision();
	int AddToScore();
	
	Vector2 GetPosition();


	Rectangle GetBoundBox();
	

private:

	int m_width;
	int m_height;
	int m_scoreToAdd;
	
	float m_speed;
	float m_speedMin = 2.0f;
	float m_speedMax = 6.0f;

	float m_xDirectionMax = 4.0f;

	Vector2 m_position;
	Vector2 m_direction;

	Rectangle m_rectangleBound;

	Color m_color;

	
	

};

