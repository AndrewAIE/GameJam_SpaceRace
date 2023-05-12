#include "Paddle.h"


Paddle::Paddle() : m_height{ }, m_width{ }, m_position{ }, m_speed{ }
{
	
	
	
}

Paddle::Paddle(int height, int width, int speed, Vector2 position) : m_height { height }, m_width { width }, m_speed{ speed }, m_position { position }
{
	
	
}

Paddle::~Paddle() 
{

}

void Paddle::Draw() 
{
	DrawRectangle(m_position.x, m_position.y, m_width, m_height, DARKBLUE);
};

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
	if (m_position.x >= GetScreenWidth() - (m_width + 25)) 
	{
		m_position.x = GetScreenWidth() - (m_width + 25);
	}
	else 
	{
		m_position.x += m_speed;
	}
	
}

Vector2 Paddle::GetPosition() 
{
	return m_position;
}
