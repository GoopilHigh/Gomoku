//
// GomokuIA.hpp for GomokuIA in /home/stephane/rendu/Gomo/Gomoku_SFML
//
// Made by Stéphane
// Login   <stephane@epitech.net>
//
// Started on  Thu Nov 10 21:03:50 2016 Stéphane
// Last update Sun Dec 11 19:36:24 2016 Jamais Thomas
//

#ifndef GOMOKUIA_HPP
#define GOMOKUIA_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <map>
#include "Goban.hpp"
#include "Ruler.hpp"

class GomokuIA : public Goban
{
private:
  std::vector<int>  _goban_test;
public:
  GomokuIA();
  ~GomokuIA();
  int   LikeMusic();
  int   LoadImage();
  int   InitGoban();
  int   GetXClick(void) {
    return ceil(event.mouseButton.x / 5 * 0.1) * 50;
  }
  int   GetYClick(void) {
    return ceil(event.mouseButton.y / 5 * 0.1) * 50;
  }
  int   EventWhite();
  int   EventBlack();
  int   Score(std::vector<int> winStones);
  int   GameLoop();
public:
  Goban                         map;
  sf::Image                     Icon;
  sf::Font                      font;
  sf::Text                      text_scoreW;
  sf::Text                      text_scoreB;
  sf::SoundBuffer               sound_buff;
  sf::SoundBuffer               sound_buffStone;
  sf::Sound                     sound;
  sf::Sound                     soundStone;
  sf::Event                     event;
  sf::Texture                   image_score;
  sf::Texture                   image_Gblack;
  sf::Texture                   image_Gwhite;
  sf::Texture                   image_Winwhite;
  sf::Texture                   image_Winblack;
  sf::Sprite                    sprite_score;
  sf::Sprite                    sprite_Gblack;
  sf::Sprite                    sprite_Gwhite;
  sf::Sprite                    sprite_Winwhite;
  sf::Sprite                    sprite_Winblack;
  int                           whiteS;
  int                           blackS;
  std::string                   whiteSS;
  std::string                   blackSS;
  std::vector<sf::Sprite>       goban_tab;
};

#endif /* ! GOMOKU_HPP */
