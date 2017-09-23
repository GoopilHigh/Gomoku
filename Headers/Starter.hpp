#ifndef STARTER_HPP
#define STARTER_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Starter
{
public:
    Starter();
    ~Starter();
    int WindowLoop();
    int ImageLoader();

public:
  sf::Event			event;
  sf::Font			font;
  sf::Texture	  image_font;
  sf::Sprite		sprite_font;
};

#endif /* ! STARTER_HPP */
