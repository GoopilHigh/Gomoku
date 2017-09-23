/*
 * @Author: Stephane.Lejeune
 * @Date: 2016-12-07 14:48:42
 * @Last Modified by: Stephane.Lejeune
 * @Last Modified time: 2016-12-07 16:31:31
 */

#include "GomokuIA.hpp"
#include "Rules.hpp"
#include "WinGame.hpp"
#include "AI.hpp"

GomokuIA::GomokuIA() : _goban_test(362, 0)
{
  InitGoban();
  LoadImage();
  GameLoop();
}


int			                GomokuIA::InitGoban()
{
  const int goban[] ={
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };
  if (!this->map.load("Res/tile.png", sf::Vector2u(50, 50), goban, 18, 18))
    return EXIT_FAILURE;
  return (0);
}

int			                GomokuIA::LikeMusic()
{
  if (!sound_buff.loadFromFile("Res/Marco_Polo.ogg"))
    return EXIT_FAILURE;
  if (!sound_buffStone.loadFromFile("Res/stone6.ogg"))
    return EXIT_FAILURE;
  sound.setBuffer(sound_buff);
  soundStone.setBuffer(sound_buffStone);
  sound.setLoop(true);
  sound.play();
  return 0;
}

int			                GomokuIA::LoadImage()
{
  if (!font.loadFromFile("Res/Japonesa.ttf"))
    return EXIT_FAILURE;
  if (!image_score.loadFromFile("Res/score.png"))
    return EXIT_FAILURE;
  if (!image_Gblack.loadFromFile("Res/GBlack.png"))
    return EXIT_FAILURE;
  if (!image_Gwhite.loadFromFile("Res/Gwhite.png"))
    return EXIT_FAILURE;
  else
    {
      sprite_score.setTexture(image_score);
      sprite_score.setPosition(950, 0);
      sprite_Gblack.setTexture(image_Gblack);
      sprite_Gblack.setOrigin(25,25);
      sprite_Gwhite.setTexture(image_Gwhite);
      sprite_Gwhite.setOrigin(25,25);
      sprite_Winwhite.setTexture(image_Winwhite);
      sprite_Winblack.setTexture(image_Winblack);
    }
  return (0);
}

int			                GomokuIA::EventWhite()
{
  int                   x(GetXClick());
  int                   y(GetYClick());
  int                   test(0);
  int                   myCase(0);

  for (auto &elem : goban_tab) {
    if (elem.getPosition().x == x && elem.getPosition().y == y)
      test = 1;
  }
  if (test == 1)
    return 1;
  if (x > 950)
    sprite_Gwhite.setPosition(950, y);
  else
    sprite_Gwhite.setPosition(x, y);
  soundStone.play();
  goban_tab.push_back(sprite_Gwhite);
  myCase = ((y / 5) * 0.1) * 19 + ((x / 5) * 0.1);
  this->_goban_test.at(myCase) = 2;
  std::cout << "X = " << x << "\tY = " << y << std::endl;
  std::cout << "Le Joueur Blanc capture la zone:\nx: " \
            << ceil(event.mouseButton.x / 5 * 0.1)      \
            << "\ny: " << ceil(event.mouseButton.y / 5 * 0.1)\
            << std::endl;
  return 0;
}

int			                GomokuIA::EventBlack()
{
  int                   x(GetXClick());
  int                   y(GetYClick());
  int                   test(0);
  int                   myCase(0);

  for (auto &elem : goban_tab) {
    if (elem.getPosition().x == x && elem.getPosition().y == y)
      test = 1;
    }
    if (test == 1 || x > 900 || y > 900)
      return 1;
  soundStone.play();
  sprite_Gblack.setPosition(x, y);
  goban_tab.push_back(sprite_Gblack);
  std::cout << "X = " << x << "\tY = " << y << std::endl;
  myCase = ((y / 5) * 0.1) * 19 + ((x / 5) * 0.1);
  this->_goban_test.at(myCase) = 1;
  std::cout << "Le Joueur Noir capture la zone:\nx: " \
            << ceil(event.mouseButton.x / 5 * 0.1)      \
            << "\ny: " << ceil(event.mouseButton.y / 5 * 0.1)\
            << std::endl;
  return 0;
}

int            			  GomokuIA::Score(std::vector<int> winStones)
{
  whiteSS = "White\nScore : \n\n  ";
  whiteSS += std::to_string(winStones[0]);
  text_scoreW.setFont(font);
  text_scoreW.setString(whiteSS);
  text_scoreW.setCharacterSize(30);
  text_scoreW.setColor(sf::Color::White);
  text_scoreW.setPosition(1030,380);
  text_scoreW.setStyle(sf::Text::Bold);

  blackSS = "Black\nScore : \n\n  ";
  blackSS += std::to_string(winStones[1]);
  text_scoreB.setFont(font);
  text_scoreB.setString(blackSS);
  text_scoreB.setCharacterSize(30);
  text_scoreB.setColor(sf::Color::White);
  text_scoreB.setPosition(1030,680);
  text_scoreB.setStyle(sf::Text::Bold);
}

int			              GomokuIA::GameLoop()
{
  sf::RenderWindow      window(sf::VideoMode(1500, 950), "GomokuIA Ninuki", sf::Style::Close);
  static int            Round;
  Ruler *ruler =        new Ruler(this->goban_tab, this->_goban_test);
  AI                    ai(*ruler, sprite_Gwhite);
  int                   res(0);

  LikeMusic();
  Round = 0;
  whiteS = 0;
  blackS = 0;
  while (window.isOpen())
    {
      while (window.pollEvent(event))
        {
          std::vector<int> stones = ruler->getNbWinStone();
          Score(stones);
          if(event.type == sf::Event::Closed || ruler->CheckThiefWinner() > 0)
          {
            sound.stop();
            window.close();
            WinGame Launch(Round);
          }
          if ((Round % 2) == 0
              && event.type == sf::Event::MouseButtonPressed
              && event.mouseButton.button == sf::Mouse::Left
              && !ruler->CheckDoubleThree(Round + 1, GetXClick(), GetYClick()))
            {
              Round++;
              res = EventBlack();
              if (res == 1)
                Round--;
              else if (ruler->CheckFor2Catch(Round) == 1)
                std::cout << "L'équipe " << Round % 2 << " à volé 2 pierres" << std::endl;
              else if (ruler->CheckForWinner(Round) == 1)
                {
                  sound.stop();
	                window.close();
                  WinGame  launch(Round);
                  std::cout << "L'équipe " << Round % 2 << " à gagné, FIVEEEE" << std::endl;
                  return 0;
                }
              if (event.mouseButton.y >= 900 && event.mouseButton.x >= 1250) {
              Rules  launch;
              }
            }
            else if (Round % 2 == 1)
            {
              ai.AIManager(Round);
              ai.Play(Round);
              std::pair<int, int>    toReturn = ai.getToReturn();
              this->_goban_test.at(toReturn.second * 19 + toReturn.first) = 2;
            //   ai.displayTab();
              Round++;
              if (ruler->CheckFor2Catch(Round) == 1)
                std::cout << "L'équipe " << Round % 2 << " à volé 2 pierres" << std::endl;
              else if (ruler->CheckForWinner(Round) == 1)
              {
                window.close();
                sound.stop();
                WinGame  launch(Round);
                std::cout << "L'équipe " << Round % 2 << " à gagné, FIVEEEE" << std::endl;
                return 0;
                }
          }
        }
      window.draw(sprite_score);
      window.draw(map);
      window.draw(text_scoreW);
      window.draw(text_scoreB);
      for (int i = 0; i != goban_tab.size(); i++)
        {
          window.draw(goban_tab[i]);
        }
      window.display();
      window.clear();
    }
  sound.stop();
  return (0);
}

GomokuIA::~GomokuIA(){}
