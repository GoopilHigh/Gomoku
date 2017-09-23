#ifndef RULER_HPP_
#define RULER_HPP_

#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Gomoku.hpp"
#include "WinGame.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Ruler
{
  public:
   typedef int (Ruler::*fct)(int, int, int, int);
  //private:
  bool   CheckPos(const int &x, const int &y);
  int    CheckFor2CatchPatern(int oldX, int oldY, int color);
  int    CheckFive(int oldX, int oldY, int color);
  void   MoveToEndLine(int *oldX, int *oldY, int color);
  int    CheckBroken3(int oldX, int oldY, int color);
  int    CheckBroken5(int oldX, int oldY, int color);
  int    CheckFuturBroken5(int oldX, int oldY, int color);
  int    CheckCase(int oldX, int oldY, int color);
  int    CheckLeft(int oldX, int oldY, int color, int max);
  int    CheckNCLeft(int oldX, int oldY, int color, int max);
  int    CheckNLeft(int oldX, int oldY, int color, int max);
  int    CheckXLeft(int oldX, int oldY, int color);
  int    CheckRight(int oldX, int oldY, int color, int max);
  int    CheckNCRight(int oldX, int oldY, int color, int max);
  int    CheckNRight(int oldX, int oldY, int color, int max);
  int    CheckXRight(int oldX, int oldY, int color);
  int    CheckUp(int oldX, int oldY, int color, int max);
  int    CheckNCUp(int oldX, int oldY, int color, int max);
  int    CheckNUp(int oldX, int oldY, int color, int max);
  int    CheckXUp(int oldX, int oldY, int color);
  int    CheckDown(int oldX, int oldY, int color, int max);
  int    CheckNCDown(int oldX, int oldY, int color, int max);
  int    CheckNDown(int oldX, int oldY, int color, int max);
  int    CheckXDown(int oldX, int oldY, int color);
  int    CheckUpLeft(int oldX, int oldY, int color, int max);
  int    CheckNCUpLeft(int oldX, int oldY, int color, int max);
  int    CheckNUpLeft(int oldX, int oldY, int color, int max);
  int    CheckXUpLeft(int oldX, int oldY, int color);
  int    CheckUpRight(int oldX, int oldY, int color, int max);
  int    CheckNCUpRight(int oldX, int oldY, int color, int max);
  int    CheckNUpRight(int oldX, int oldY, int color, int max);
  int    CheckXUpRight(int oldX, int oldY, int color);
  int    CheckDownLeft(int oldX, int oldY, int color, int max);
  int    CheckNCDownLeft(int oldX, int oldY, int color, int max);
  int    CheckNDownLeft(int oldX, int oldY, int color, int max);
  int    CheckXDownLeft(int oldX, int oldY, int color);
  int    CheckDownRight(int oldX, int oldY, int color, int max);
  int    CheckNCDownRight(int oldX, int oldY, int color, int max);
  int    CheckNDownRight(int oldX, int oldY, int color, int max);
  int    CheckXDownRight(int oldX, int oldY, int color);
  void   Remove2(int color);
  void   Remove5(int color);
  void   ChangePos(int &x, int &y, const int &dir);
  std::pair<int, int> ChangePosRet(int x, int y, const int &dir, int nb);
  bool   CheckFreeFive(const int &x, const int &y, const int &dir, const int &color);
  int    CheckAround2(int &x, int &y, const int &color, const int &dir, const int i);
  int    TryNonCatch(int x, int y, int color, int dir1, int dir2);

  fct                                     _check[7];
  std::vector<int>                        test;
  std::vector<std::pair<int, int> >       to_remove;
  sf::Sound                               sound;
  sf::SoundBuffer                         sound_buffDeath;
  int                                     p1_win_stone;
  int                                     p2_win_stone;
  std::vector<int>                        nb_win_stone;
  std::vector<int>                        &goban_test;
  std::vector<sf::Sprite>                 &_goban_tab;
  int                                     dir;
// public:
Ruler (std::vector<sf::Sprite> &goban_tab, std::vector<int> &goban_test) : test(400, 0), _goban_tab(goban_tab), goban_test(goban_test) {
     InitRuler();
   };

 ~Ruler()
 {
    this->to_remove.clear();
    this->nb_win_stone.clear();
    this->goban_test.clear();
    this->_goban_tab.clear();
 };

   std::vector<int> getNbWinStone(void) {
     return this->nb_win_stone;
   }
   std::vector<int>* getGobanTest(void) {
     return &this->goban_test;
   }

   void AddSpriteToVector(sf::Sprite sprite_Gwhite)
   {
      _goban_tab.push_back(sprite_Gwhite);
   }

   void AddToGobanTest(int i, int nb)
   {
      goban_test[i] = nb;
   }

   void InitRuler(void) {
      this->dir = 0;
      this->nb_win_stone.push_back(0);
      this->nb_win_stone.push_back(0);
      this->_check[0] = &Ruler::CheckLeft;
      this->_check[1] = &Ruler::CheckRight;
      this->_check[2] = &Ruler::CheckUp;
      this->_check[3] = &Ruler::CheckDown;
      this->_check[4] = &Ruler::CheckUpLeft;
      this->_check[5] = &Ruler::CheckUpRight;
      this->_check[6] = &Ruler::CheckDownLeft;
      this->_check[7] = &Ruler::CheckDownRight;
   }

   int CheckThiefWinner(void) {
     if (this->nb_win_stone[1] >= 10) {
       std::cout << "L'équipe Noire a gagné avec 10 pierres volées." << std::endl;
       return 1;
     }
     if (this->nb_win_stone[0] >= 10) {
       std::cout << "L'équipe Blanche a gagné avec 10 pierres volées." << std::endl;
       return 2;
     }
     return 0;
   }
   int CheckForWinner(const int &Round);
   int CheckFor2Catch(const int &Round);
   bool CheckDoubleThree(const int &round, int x, int y);
};

#endif /* !_RULER_HPP_ */
