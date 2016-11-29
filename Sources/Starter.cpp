#include "Starter.hpp"
#include "Gomoku.hpp"

Starter::Starter()
{
    ImageLoader();
    WindowLoop();
}

int Starter::ImageLoader()
{
    if (!image_font.loadFromFile("Res/GomoShenron.png"))
    return EXIT_FAILURE;
    sprite_font.setTexture(image_font);
    sprite_font.setOrigin(400,300);
    sprite_font.setPosition(400, 300);
}

int Starter::WindowLoop()
{
sf::RenderWindow	window(sf::VideoMode(800, 600), "Gomoku Ninuki", sf::Style::Close);
while (window.isOpen())
    {
      while (window.pollEvent(event))
	    {
	  if(event.type == sf::Event::Closed)
	    window.close();
	  if (event.type == sf::Event::MouseButtonPressed)
	    {
	    if (event.mouseButton.button == sf::Mouse::Left)
		    {
	        window.close();
            Gomoku  launch;
            launch;
	        }
	    }
        window.draw(sprite_font);
        window.display();
        window.clear();
        }
    }
  return (0);
}

Starter::~Starter(){}