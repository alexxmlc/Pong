#include "Bath.h"
using namespace sf;

//Implementation of Bat constructor
Bat::Bat(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(Vector2f(50, 5));
	m_Shape.setPosition(m_Position);
}

FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds();			//Returns a FloatRect that is initialized with thr coordinates of 4 corners of m_Shape
}

RectangleShape Bat::getShape()
{
	return m_Shape;								//Passes a copy of m_Shape
}

void Bat::moveLeft()
{
	m_MovingLeft = true;
}

void Bat::moveRight()
{
	m_MovingRight = true;
}

void Bat::stopLeft()
{
	m_MovingLeft = false;
}

void Bat::stopRight()
{
	m_MovingRight = false;
}

void Bat::update(Time dt)
{
	if (m_MovingLeft)
	{
		m_Position.x -= m_Speed * dt.asSeconds();
	}

	if (m_MovingRight)
	{
		m_Position.x += m_Speed * dt.asSeconds();
	}
	m_Shape.setPosition(m_Position);
}