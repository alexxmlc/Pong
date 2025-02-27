#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f m_Position;
	RectangleShape m_Shape;

	float m_Speed = 700.0f;
	float m_DirectionX = .2f;
	float m_DirectionY = .2f;
	bool m_canScore = true;

public:
	Ball(float startX, float startY);
	FloatRect getPostition();
	RectangleShape getShape();
	float getXVelocity();
	void reboundSides();
	void reboundBatOrTop();
	void reboundBottom();
	void update(Time dt);
	float getDirectionY();
};