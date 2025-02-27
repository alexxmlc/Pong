#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
	Vector2f m_Position;				//Holds the horizontal and vert pos of the bat
	RectangleShape m_Shape;
	float m_Speed = 700.0f;
	bool m_MovingRight = false;
	bool m_MovingLeft = false;
public:
	Bat(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(Time dt);
};