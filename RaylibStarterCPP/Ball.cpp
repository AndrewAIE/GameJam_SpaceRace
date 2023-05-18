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
		m_direction.y *= -1.0f;			
	};
}

Rectangle Ball::GetBoundBox()
{
	return m_rectangleBound;
}

