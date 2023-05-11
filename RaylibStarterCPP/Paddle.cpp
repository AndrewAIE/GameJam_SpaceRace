#include "Paddle.h"
#include "raylib.h"

Paddle::Paddle() {
	m_height = 0;
	m_width = 0;
	m_speed = 0;
	m_position.x = 0;
	m_position.y = 0;
	
}

Paddle::Paddle(int height, int width, int x, int y, int speed) 
{
	m_height = height;
	m_width = width;
	m_position.x = x;
	m_position.y = y;
	m_speed = speed;
}

Paddle::~Paddle() 
{

}



void Paddle::Draw() 
{
	DrawRectangle(m_position.x, m_position.y, m_width, m_height, BLACK);
};

void Paddle::SetPosition(Point2D position) 
{
	m_position = position;
}

void Paddle::MoveLeft() 
{
	if (m_position.x <= m_width / 2) 
	{
		m_position.x = m_width / 2;
	}
	else 
	{
		m_position.x -= m_speed;
	}
	
}

void Paddle::MoveRight() 
{
	if (m_position.x >= GetScreenWidth() - (m_width / 2)) 
	{
		m_position.x = GetScreenWidth() - (m_width / 2);
	}
	else 
	{
		m_position.x += m_speed;
	}
	
}

Point2D Paddle::GetPosition() 
{
	return m_position;
}
