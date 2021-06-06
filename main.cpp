//#include "SFML/Graphics.hpp"
//#include <iostream>
//#include "Menu.h"
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(600, 600), "SISTEM DE FACTURARE");
//
//	Menu menu(window.getSize().x, window.getSize().y);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//
//		while (window.pollEvent(event))
//		{
//			switch (event.type)
//			{
//			case sf::Event::KeyReleased:
//				switch (event.key.code)
//				{
//				case sf::Keyboard::Up:
//					menu.MoveUp();
//					break;
//
//				case sf::Keyboard::Down:
//					menu.MoveDown();
//					break;
//
//				case sf::Keyboard::Return:
//					switch (menu.GetPressedItem())
//					{
//					case 0:
//						std::cout << "A fost selectat modul de admin" << std::endl;
//						break;
//					case 1:
//						std::cout << "A fost selectat modul de user" << std::endl;
//						break;
//					case 2:
//						window.close();
//						break;
//					}
//
//					break;
//				}
//
//				break;
//			case sf::Event::Closed:
//				window.close();
//
//				break;
//
//			}
//		}
//
//		window.clear();
//
//		menu.draw(window);
//
//		window.display();
//	}
//}

#include<iostream>
#include<SFML\Graphics.hpp>
#include "Main_menu.h"

using namespace std;
using namespace sf;

int page_number;

int main()
{
	while (true)
	{
		sf::RenderWindow window(VideoMode(400, 400), "Sistem de facturare", sf::Style::Close);
		Main_menu menu(600, 600);
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Up)
					{
						menu.moveUp();
						break;
					}
					if (event.key.code == sf::Keyboard::Down)
					{
						menu.moveDown();
						break;
					}

					//choose page
					if (event.key.code == sf::Keyboard::Return) //enter
					{

						if (menu.mainMenuPressed() == 0)
						{
							window.close();
							page_number = 0;
						}
						if (menu.mainMenuPressed() == 1)
						{
							window.close();
							page_number = 1;
						}
						if (menu.mainMenuPressed() == 2)
						{
							window.close();
							page_number = 2;
						}
					}


				}

			}
			window.clear();
			menu.draw(window);
			window.display();
		}
		if (page_number == 0)
		{
			//play
			sf::RenderWindow window_play(VideoMode(300, 300), "Admin", sf::Style::Close);
			while (window_play.isOpen())
			{
				sf::Event event;
				while (window_play.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window_play.close();

				}
				window_play.clear();

				window_play.display();
			}
		}
		if (page_number == 1)
		{
			//options
			sf::RenderWindow window_play(VideoMode(300, 300), "User", sf::Style::Close);
			while (window_play.isOpen())
			{
				sf::Event event;
				while (window_play.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window_play.close();

				}
				window_play.clear();
				window_play.display();
			}
		}
		if (page_number == 2)
		{
			//exit
			break;
		}

	}

	return 0;
}