#include <SFML/Graphics.hpp>
#include <iostream>
#include "ColorTable.h"
#include "Game.h"
#include "Scene.h"

struct UserEvent 
{
	enum class What
	{
		Nothing,
		KeyPressed

	} what;
	enum class Action 
	{
		GamePaused,
		GameRun
	} pause;
	UserEvent()
	{
		this->what = What::Nothing;
		this->pause = Action::GamePaused;
	};
	void pauseKeyPressed() 
	{
		if (pause == Action::GameRun) 
		{
			this->pause = Action::GamePaused;
		}
		else if (pause == Action::GamePaused) 
		{
			this->pause = Action::GameRun;
		}
	}
	void toDefault() 
	{
		what = What::Nothing;
		pause = Action::GameRun;
	}
	
};

int main(int argc, char* argv[])
{

	srand(time(0));
	Scene scene({ 0,0 }, { 1000,1000}, 100, 100);
	//for (int i = 0; i < 100; ++i) 
	//{
	//	for (int j = 0; j < 100; ++j) 
	//	{
	//		if (static_cast<float>(rand())/ RAND_MAX > 0.5)
	//		{
	//			scene.setAlliveAt(i, j);
	//		}
	//	}
	//}
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Title");

	sf::Clock clock;
	UserEvent UEvent;
	while (window.isOpen()) 
	{
		sf::Vector2f mouse_coords = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		float time = clock.getElapsedTime().asSeconds();
		sf::Event event;
		
		while (window.pollEvent(event)) 
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space) 
				{
					UEvent.what = UserEvent::What::KeyPressed;
					UEvent.pauseKeyPressed();
				}
				break;
			case sf::Event::MouseButtonPressed:
				
				if (UEvent.pause == UserEvent::Action::GamePaused && event.key.code == sf::Mouse::Left) 
				{
					sf::Vector2i coords = scene.getCoordsByPoos(mouse_coords);

					if (coords.x != -1) 
					{
						scene.setAlliveAt(coords.y, coords.x);
					}
				}
				else if (UEvent.pause == UserEvent::Action::GamePaused && event.key.code == sf::Mouse::Right) 
				{
					sf::Vector2i coords = scene.getCoordsByPoos(mouse_coords);
					if (coords.x != -1) 
					{
						scene.setDeadAt(coords.y, coords.x);
					}
				}
				break;
				default :
				break;
			}
		}
		if (UEvent.pause == UserEvent::Action::GameRun && time >= 0.05) 
		{
			time = 0;
			clock.restart();
			scene.update();
		}

		window.clear(sf::Color::White);
		window.draw(scene);
		window.display();
	}

	return 0;
}