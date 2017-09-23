#include "WinGame.hpp"
#include "Starter.hpp"
#include "Gomoku.hpp"

WinGame::WinGame(int Round)
{
    ImageLoader();
    WindowLoop(Round);
}

int WinGame::ImageLoader()
{
    if (!image_WinWhite.loadFromFile("Res/wolvesWhite.png"))
    return EXIT_FAILURE;
    if (!image_WinBlack.loadFromFile("Res/wolvesBlack.png"))
    return EXIT_FAILURE;
    sprite_WinWhite.setTexture(image_WinWhite);
    sprite_WinWhite.setOrigin(250,150);
    sprite_WinWhite.setPosition(250, 150);
    sprite_WinBlack.setTexture(image_WinBlack);
    sprite_WinBlack.setOrigin(250,150);
    sprite_WinBlack.setPosition(250, 150);
}

int WinGame::WindowLoop(int Round)
{
sf::RenderWindow	window(sf::VideoMode(800, 420), "Finish", sf::Style::Close);
while (window.isOpen())
    {
    while (window.pollEvent(event))
	    {
        if (Round % 2 == 0)
            window.draw(sprite_WinWhite);
        else
            window.draw(sprite_WinBlack);
            if (event.type == sf::Event::MouseButtonPressed)
            {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if (event.mouseButton.y >= 50 && event.mouseButton.y <= 200)
                {
                std::cout << "Reply" << std::endl;
	            window.close();
                Starter  launch;
                }
                if (event.mouseButton.y >= 250 && event.mouseButton.y <= 360)
                {
                std::cout << "Quit" << std::endl;
	            window.close();
                return 0;
                }
            }
            }
  	    if(event.type == sf::Event::Closed)
        {
  	    window.close();
        return 0;
        }
        else
        {
        window.display();
        window.clear();
        }
        }
    }
return (0);
}

WinGame::~WinGame(){}
