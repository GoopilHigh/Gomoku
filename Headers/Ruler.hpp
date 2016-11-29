#ifndef RULER_HPP_
#define RULER_HPP_

#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Ruler
{
private:
  int    CheckFor2CatchPatern(int oldX, int oldY, int color);
  int    CheckFive(int oldX, int oldY, int color);
  void   MoveToEndLine(int *oldX, int *oldY, int color);
  int    CheckBroken3(int oldX, int oldY, int color);
  int    CheckBroken5(int oldX, int oldY, int color);
  int    CheckFuturBroken5(int oldX, int oldY, int color);
  int    CheckCase(int oldX, int oldY, int color);
  int    CheckLeft(int oldX, int oldY, int color, int max);
  int    CheckNLeft(int oldX, int oldY, int color, int max);
  int    CheckXLeft(int oldX, int oldY, int color);
  int    CheckRight(int oldX, int oldY, int color, int max);
  int    CheckNRight(int oldX, int oldY, int color, int max);
  int    CheckXRight(int oldX, int oldY, int color);
  int    CheckUp(int oldX, int oldY, int color, int max);
  int    CheckNUp(int oldX, int oldY, int color, int max);
  int    CheckXUp(int oldX, int oldY, int color);
  int    CheckDown(int oldX, int oldY, int color, int max);
  int    CheckNDown(int oldX, int oldY, int color, int max);
  int    CheckXDown(int oldX, int oldY, int color);
  int    CheckUpLeft(int oldX, int oldY, int color, int max);
  int    CheckNUpLeft(int oldX, int oldY, int color, int max);
  int    CheckXUpLeft(int oldX, int oldY, int color);
  int    CheckUpRight(int oldX, int oldY, int color, int max);
  int    CheckNUpRight(int oldX, int oldY, int color, int max);
  int    CheckXUpRight(int oldX, int oldY, int color);
  int    CheckDownLeft(int oldX, int oldY, int color, int max);
  int    CheckNDownLeft(int oldX, int oldY, int color, int max);
  int    CheckXDownLeft(int oldX, int oldY, int color);
  int    CheckDownRight(int oldX, int oldY, int color, int max);
  int    CheckNDownRight(int oldX, int oldY, int color, int max);
  int    CheckXDownRight(int oldX, int oldY, int color);
  void   Remove2(int color);
  void   Remove5(int color);

  std::vector<int>                        test;
  std::vector<std::pair<int, int> >       to_remove;
  int                                     p1_win_stone;
  int                                     p2_win_stone;
  std::vector<int>                        nb_win_stone;
  std::vector<int>                        goban_test;
  std::vector<sf::Sprite>                 &_goban_tab;
public:
   Ruler (std::vector<sf::Sprite> &goban_tab) : test(561, 0),  _goban_tab(goban_tab), goban_test(test) {
     InitRuler();
   };

   std::vector<int> getNbWinStone(void) {
     return this->nb_win_stone;
   }
   std::vector<int>* getGobanTest(void) {
     return &this->goban_test;
   }
   void InitRuler(void) {
     this->nb_win_stone.push_back(0);
     this->nb_win_stone.push_back(0);
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
};

#endif /* !_RULER_HPP_ */
