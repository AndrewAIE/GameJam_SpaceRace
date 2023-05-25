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
		int ballMid = (m_position.x + m_width) / 2;
		
		int objectXLeft = object.x;
		int objectXRight = object.x + object.width;
		int objectXMid = (objectXLeft + objectXRight) / 2;

		if (m_position.y > (GetScreenHeight() / 2)) 
		{
			
			m_speed += 0.2;

			if (m_speed < m_speedMin)
			{
				m_speed = m_speedMin;
			}
			else if (m_speed > m_speedMax)
			{
				m_speed = m_speedMax;
			}
		}
		else 
		{
			m_scoreToAdd = (int)m_speed;
		}

		if (ballMid == objectXLeft) 
		{
			m_direction.x = -m_xDirectionMax;
		}
		else if (ballMid > objectXLeft && ballMid <= objectXMid) 
		{
			if (m_direction.x > 0) 
			{
				m_direction.x *= -1;
			}
			else if (m_direction.x < 0) 
			{
				m_direction.x += m_direction.x * 0.3;
			}

			if (m_direction.x < -m_xDirectionMax) 
			{
				m_direction.x = -m_xDirectionMax;
			}
		}
		else if (ballMid == objectXRight)
		{
			m_direction.x = m_xDirectionMax;
		}
		else if (ballMid < objectXRight && ballMid > objectXMid) 
		{
			if (m_direction.x < 0)
			{
				m_direction.x *= -1;
			}
			else if (m_direction.x > 0)
			{
				m_direction.x += m_direction.x * 0.3;
			}

			if (m_direction.x > m_xDirectionMax)
			{
				m_direction.x = m_xDirectionMax;
			}
		}

		m_direction.y *= -1;
		
		

		//when hold down space, reduce speed by 1 and add acceleration to appropriate axis


	};
}

void Ball::EdgeCollision()
{
	if (m_position.x >= GetScreenWidth() - 25) 
	{
		m_direction.x = -1;
	}
	if (m_position.x <= 0) 
	{
		m_direction.x = 1;
	}
	if (m_position.y <= GetScreenHeight()/6) 
	{
		m_direction.y = 1;
	}
	if (m_position.y >= GetScreenHeight()) 
	{
		m_direction.y = -1;
	}
}

int Ball::AddToScore() 
{
	return m_scoreToAdd;
}

Rectangle Ball::GetBoundBox()
{
	return m_rectangleBound;
}

Vector2 Ball::GetPosition() 
{
	return m_position;
}

