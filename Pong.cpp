#include "Bath.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Pong", Style::Fullscreen);

	int score = 0;
	int lives = 3;

	Bat bat(1920 / 2, 1080 - 20);							//Creating a bat and a ball
	Ball ball(1920 / 2, 0);

	Text hud;
	Font font;
	font.loadFromFile("fonts/DS-DIGI.ttf");
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(Color::White);
	hud.setPosition(20, 20);
	
	Clock clock;											//Clock for timing everything

	while (window.isOpen())
	{
		/*
	   Handle the player input
	   ****************************
	   ****************************
	   ****************************
	   */
		Event event;
		while (window.pollEvent(event))						//Checks for the events in the event queue
		{
			if (event.type == Event::Closed)				//Quit the game when window is closed
				window.close();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}
	   /*
	   Update the bat, the ball and the HUD
	   *****************************
	   *****************************
	   *****************************
	   */
		Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);
		std::stringstream ss;
		ss << "Score:" << score << "  Lives:" << lives;
		hud.setString(ss.str());

		if (ball.getPostition().top > window.getSize().y)
		{
			ball.reboundBottom();
			lives--;
			
			if (lives < 1)
			{
				score = 0;
				lives = 3;
			}
		}

		if (ball.getPostition().top < 0)
		{
			ball.reboundBatOrTop();
		}

		if (ball.getPostition().left < 0 ||	ball.getPostition().left > window.getSize().x) 
		{
			ball.reboundSides();
		}

		bool batCollisionFlag = false;
		if (ball.getPostition().intersects(bat.getPosition()) && !batCollisionFlag && ball.getDirectionY())
		{
			ball.reboundBatOrTop();
			score++;
			batCollisionFlag = true;
		}
		else
		{
			batCollisionFlag = false;
		}
	   /*
	   Draw the bat, the ball and the HUD
	   *****************************
	   *****************************
	   *****************************
	   */
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());				//Grab the RectangleShape instance from the Bat instance and draw it
		window.draw(ball.getShape());
		window.display();
	}
	return 0;
}
