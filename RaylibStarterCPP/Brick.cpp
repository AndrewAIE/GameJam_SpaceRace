#include "Brick.h"

Brick::Brick() : m_height {}, m_width {}, m_position {}, m_color {}
{
	m_rectangleBound = { m_position.x, m_position.y, (float)m_width, (float)m_height };
}

Brick::Brick(int height, int width, Vector2 position) : m_height { height }, m_width { width }, m_position { position }, m_color {}
{
	m_rectangleBound = { m_position.x, m_position.y, (float)m_width, (float)m_height };
	m_isDestroyed = false;
}

Brick::~Brick()
{
	
}

void Brick::Draw() 
{
	if (!m_isDestroyed) 
	{
		DrawRectangle(m_position.x, m_position.y, m_width, m_height, m_color);
	}
	
}

void Brick::AssignColor(int yPos)
{
	switch (yPos) 
	{
	case 0:
	case 1:
		m_color = RED;
		break;
	case 2:
	case 3:
		m_color = ORANGE;
		break;
	case 4:
	case 5:
		m_color = GREEN;
		break;
	case 6:
	case 7:
		m_color = YELLOW;
		break;
	}
}

void Brick::Destroy() 
{	
	m_isDestroyed = true;
}

bool Brick::GetDestroyed() 
{
	return m_isDestroyed;
}

Rectangle Brick::GetBoundBox()
{
	return m_rectangleBound;
}




