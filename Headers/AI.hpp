#ifndef AI_HPP_
# define AI_HPP_

#include "Ruler.hpp"
#include <vector>

#define MAX_X 18
#define MAX_Y 18

enum Dir {
  RIGHT,
  UP,
  UPRIGHT,
  DOWNRIGHT
};

typedef struct ChoiceElem {
  std::vector<std::pair<int, int> > positions;
  int dir;
  int nb;
  int color;
  bool stole;
} CHOICEELEM;

class AI {
private:

  Ruler &_ruler;
  std::vector<CHOICEELEM> _vChoiceElem;
  sf::Sprite &_sprite_Gwhite;
  std::pair<int, int>   _oldPos;
  std::pair<int, int>   _toReturn;


  void ChangePos(int &x, int &y, const int &dir);
  void ChangePos2(int &x, int &y, const int &dir);
  bool CheckVElems(std::vector<std::pair<int, int> > pos);
  void AddChoiceElem(int &x, int &y, const int &color);
  void CheckBoard(void);
  void  FirstMove();
  void  TakeBetterChoice();
  int  StoleThisChoice(CHOICEELEM elem);
  int  ContinueThisChoice(CHOICEELEM elem);
  std::pair<int, int> ChangePosRet(int x, int y, const int &dir, int nb);
  void  PlayAt(std::pair<int, int> coo);
  void  PlayByDefault();
  int   CheckDirForFutur(int &x, int &y);

public:
  AI(Ruler &ruler, sf::Sprite sprite_Gwhite) : _ruler(ruler), _sprite_Gwhite(sprite_Gwhite) {} ;

  void AIManager(int Round);
  std::pair<int, int> Play(int Round);
  void displayTab();
  std::pair<int, int>   getToReturn()
  {
    return _toReturn;
  }
};

#endif /* !_AI_HPP_ */
