#include "Ball.h"

Ball::Ball() : m_width{}, m_speed{}, m_position{}, m_direction{}, m_color {}
{

}

Ball::Ball(int width, int height, float speed, Vector2 position, Vector2 direction, Color color) : m_width{ width }, m_height{ height }, m_speed { speed },
			m_position{ position }, m_direction{ direction }, m_color { color }
{
	
}

Ball::~Ball() 
{

}

void Ball::Draw() 
{
	DrawRectangle(m_position.x, m_position.y, m_width, m_height, m_color);
}

void Ball::Update() 
{
	Move();
	m_rectangleBound = { m_position.x, m_position.y, (float)m_width, (float)m_height };
}

void Ball::Move() 
{
	m_position.x += m_speed * m_direction.x;
	m_position.y += m_speed * m_direction.y;
}

void Ball::CheckCollision(Rectangle object) 
{
	
	if (CheckCollisionRecs(m_rectangleBound, object)) 
	{
		m_direction.y *= -1;

		//find x distance
		//if distance > ball width + other width
		// x *= -1
	};
}

void Ball::EdgeCollision()
{
	if (m_position.x >= GetScreenWidth() - 25 || m_position.x <= 0) 
	{
		m_direction.x *= -1.0f;
	}
	if (m_position.y >= GetScreenHeight() || m_position.y <= 0) 
	{
		m_direction.y *= -1.0f;
	}
}

Rectangle Ball::GetBoundBox()
{
	return m_rectangleBound;
}

Vector2 Ball::GetPosition() 
{
	return m_position;
}

