#include "Main_menu.h"


Main_menu::Main_menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf")) {}

	//play
	mainMenu[0].setFont(font);
	mainMenu[0].setColor(sf::Color::Red);
	mainMenu[0].setString("Admin");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(sf::Vector2f(width / 2, height / (Max_main_menu + 1)));

	//options
	mainMenu[1].setFont(font);
	mainMenu[1].setColor(sf::Color::White);
	mainMenu[1].setString("User");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(sf::Vector2f(width / 2, height / (Max_main_menu + 1) * 2));


	//exit
	mainMenu[2].setFont(font);
	mainMenu[2].setColor(sf::Color::White);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setPosition(sf::Vector2f(width / 2, height / (Max_main_menu + 1) * 3));

	mainMenuSelected = 0;  //start from zero index (play)

}


Main_menu::~Main_menu()
{
}


//********************************Functia care deseneaza meniul**********************************************//
void Main_menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainMenu[i]);
	}
}

//********************************functia pentru mers in sus***************************************************
void Main_menu::moveUp()
{
	if (mainMenuSelected - 1 >= -1) // check if not on the first item (play)

	{

		mainMenu[mainMenuSelected].setColor(sf::Color::White);  //change the pervious item's color

		mainMenuSelected--;  //move to the upper item       
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}
		mainMenu[mainMenuSelected].setColor(sf::Color::Red); //change the new item's color
	}
}

//********************************functia pentru mers in jos***************************************************
void Main_menu::moveDown()
{
	if (mainMenuSelected + 1 <= Max_main_menu) //check if not on the last item (exit)

	{
		mainMenu[mainMenuSelected].setColor(sf::Color::White);  //change the pervious item's color

		mainMenuSelected++;  //move to the lower item
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setColor(sf::Color::Red);           //change the new item's color

	}
}