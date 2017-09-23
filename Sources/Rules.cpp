#include "Starter.hpp"
#include "Rules.hpp"

Rules::Rules()
{
    ImageLoader();
    WindowLoop();
}

int Rules::ImageLoader()
{
    if (!image_font.loadFromFile("Res/r__gles_gomoku.png"))
    return EXIT_FAILURE;
    sprite_font.setTexture(image_font);
    sprite_font.setOrigin(250,150);
    sprite_font.setPosition(250, 150);
}

int Rules::WindowLoop()
{
sf::RenderWindow	window(sf::VideoMode(500, 400), "Rules", sf::Style::Close);
while (window.isOpen())
    {
    while (window.pollEvent(event))
	    {
	    if(event.type == sf::Event::Closed)
	        window.close();
        window.draw(sprite_font);
        window.display();
        window.clear();
        }
    }
return (0);
}

Rules::~Rules(){}