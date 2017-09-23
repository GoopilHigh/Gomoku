
#ifndef WINGAME_HPP
#define WINGAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
//#include <keyboard.h>
#include <iostream>

class WinGame
{
public:
    WinGame(int Round);
    ~WinGame();
    int WindowLoop(int Round);
    int ImageLoader();

public:
  sf::Event			event;
  sf::Font			font;
  sf::Texture	    image_WinWhite;
  sf::Texture	    image_WinBlack;
  sf::Sprite		sprite_WinBlack;
  sf::Sprite		sprite_WinWhite;
};

#endif /* ! WINGAME_HPP */