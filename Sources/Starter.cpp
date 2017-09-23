/*
 * @Author: Stephane.Lejeune
 * @Date: 2016-12-06 15:15:12
 * @Last Modified by: Stephane.Lejeune
 * @Last Modified time: 2016-12-07 15:25:13
 */

#include "Starter.hpp"
#include "Gomoku.hpp"
#include "GomokuIA.hpp"
#include "Rules.hpp"

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
	  if (event.type == sf::Event::MouseButtonPressed)
	  {
	    if (event.mouseButton.button == sf::Mouse::Left)
		  {
      if (event.mouseButton.y >= 250 && event.mouseButton.y <= 370)
      {
        std::cout << "Player" << std::endl;
	      window.close();
        Gomoku  launch;
      }
      else if (event.mouseButton.y >= 370 && event.mouseButton.y <= 500)
      {
      std::cout << "Comput" << std::endl;
	    window.close();
      GomokuIA start;
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
    window.draw(sprite_font);
    window.display();
    window.clear();
      }
    }
  }
return (0);
}

Starter::~Starter(){}
