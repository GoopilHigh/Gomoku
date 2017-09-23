/*
 * @Author: Stephane.Lejeune 
 * @Date: 2016-12-06 15:02:53 
 * @Last Modified by: Stephane.Lejeune
 * @Last Modified time: 2016-12-06 15:04:31
 */

#ifndef RULES_HPP
#define RULES_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
//#include <keyboard.h>
#include <iostream>

class Rules
{
public:
    Rules();
    ~Rules();
    int WindowLoop();
    int ImageLoader();

public:
  sf::Event			event;
  sf::Font			font;
  sf::Texture	    image_font;
  sf::Sprite		sprite_font;
};

#endif /* ! RULES_HPP */