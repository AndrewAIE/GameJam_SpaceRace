#include "Paddle.h"


Paddle::Paddle() : m_height{ }, m_width{ }, m_position{ }, m_speed{ }
{
	
	
	
}

Paddle::Paddle(int height, int width, int speed, Vector2 position) : m_height { height }, m_width { width }, m_speed{ speed }, m_position { position }
{
	m_rectangleBound = { m_position.x, m_position.y, (float)m_width, (float)m_height };
	
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
		m_rectangleBound.x = m_position.x;
	}
	else 
	{
		m_position.x -= m_speed;
		m_rectangleBound.x = m_position.x;
	}	
}


void Paddle::MoveRight() 
{
	if (m_position.x >= GetScreenWidth() - (m_width + 25)) 
	{
		m_position.x = GetScreenWidth() - (m_width + 25);
		m_rectangleBound.x = m_position.x;
	}
	else 
	{
		m_position.x += m_speed;
		m_rectangleBound.x = m_position.x;
	}	
}

Rectangle Paddle::GetBoundBox()
{
	return m_rectangleBound;
}
