#include "Ball.h"

Ball::Ball() : m_radius{}, m_speed{}, m_position{}, m_color {}
{

}

Ball::Ball(int radius, Vector2 speed, Vector2 position, Color color) : m_radius{ radius }, m_speed{ speed }, m_position{ position }, m_color { color }
{

}

Ball::~Ball() 
{

}

void Ball::Draw() 
{
	DrawCircle(m_position.x, m_position.y, m_radius, m_color);
}

void Ball::Update() 
{

}

void Ball::Move() 
{
	m_position.x += m_speed.x;
	m_position.y += m_speed.y;
}
