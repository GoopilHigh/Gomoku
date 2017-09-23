#include "AI.hpp"

bool CompareElems(const CHOICEELEM &choiceElem1, const CHOICEELEM &choiceElem2) {
  return choiceElem1.nb > choiceElem2.nb && choiceElem1.color <= choiceElem2.color;
}

void AI::ChangePos2(int &x, int &y, const int &dir)
{
  switch (dir) {
    case 0:
      --y;
      break;
    case 1:
      ++y;
      break;
    case 2:
      ++x;
      break;
    case 3:
      --x;
      break;
    case 4:
      --x;
      --y;
      break;
    case 5:
      ++x;
      --y;
      break;
    case 6:
      --x;
      ++y;
      break;
    case 7:
      ++x;
      ++y;
      break;
    }
}


void AI::ChangePos(int &x, int &y, const int &dir) {
  switch (dir) {
    case 0:
      ++x;
      break;
    case 1:
      ++y;
      break;
    case 2:
      ++x;
      --y;
      break;
    case 3:
      ++x;
      ++y;
      break;
    }
}


std::pair<int, int> AI::ChangePosRet(int x, int y, const int &dir, int nb)
{
  int                   i = 0;

  if (nb < 0)
  {
    nb = nb - (nb * 2);
    while (i <  nb)
      {
        switch (dir)
          {
             case 0:
               --x;
               break;
             case 1:
               ++y;
               break;
             case 2:
               ++x;
               --y;
               break;
             case 3:
               ++x;
               ++y;
               break;
          }
        i++;
      }
   return (std::make_pair(x, y));
  }
  while (i <  nb)
    {
      switch (dir)
        {
           case 0:
            ++x;
            break;
          case 1:
            --y;
            break;
          case 2:
            --x;
            ++y;
            break;
          case 3:
            --x;
            --y;
            break;
        }
      i++;
    }
  return (std::make_pair(x, y));
}

bool AI::CheckVElems(std::vector<std::pair<int, int>> pos) {
  for (auto &elem : this->_vChoiceElem) {
    for (auto &pVector : elem.positions) {
      for (auto &pElem : pos) {
        if (pElem == pVector)
          return true;
      }
    }
  }
  return false;
}

void AI::AddChoiceElem(int &x, int &y, const int &color) {
  int tmpX(x), tmpY(y), dir(0), nb(0);
  std::vector<std::pair<int, int>> positions;

  while (dir < 4) {
    while (this->_ruler.CheckCase(tmpX, tmpY, color) == 1) {
      if (nb == 0)
        positions.push_back(std::make_pair(tmpX, tmpY));
      this->ChangePos(tmpX, tmpY, dir);
      ++nb;
    }
    if (nb >= 2) {
      positions.push_back(std::make_pair(tmpX, tmpY));
      if (!this->CheckVElems(positions))
        this->_vChoiceElem.push_back({positions, dir, nb, color, false});
    }
    positions.clear();
    nb = 0;
    tmpX = x;
    tmpY = y;
    ++dir;
  }
}

void AI::CheckBoard(void) {
  int x(0), y(0);

  if (!this->_vChoiceElem.empty()) {
    std::vector<CHOICEELEM> tmp;
    this->_vChoiceElem.swap(tmp);
  }
  this->_vChoiceElem.clear();
  for (int color(1); color < 3; ++color) {
    while (y <= MAX_Y) {
      if (this->_ruler.CheckCase(x, y, color) == 1)
        this->AddChoiceElem(x, y, color);
        ++x;
        if (x > MAX_X) {
          x = 0;
          ++y;
        }
    }
    x = y = 0;
  }
  if (this->_vChoiceElem.size() > 1)
    std::sort(this->_vChoiceElem.begin(), this->_vChoiceElem.end(), CompareElems);
}

void AI::AIManager(int Round) {
   if (Round == 1)
      this->FirstMove();
   else
      this->CheckBoard();
}

int  AI::StoleThisChoice(CHOICEELEM elem)
{
   std::pair<int, int>  newPosLess(ChangePosRet(elem.positions[0].first, elem.positions[0].second, elem.dir, 1));
   std::pair<int, int>  newPosMore(ChangePosRet(elem.positions[1].first, elem.positions[1].second, elem.dir, 0));

   // std::cout << "Coo du vector x1 = " << newPosLess.first << " y1 = " << newPosLess.second << "\tx2 = " << newPosMore.first << " y2 = " << newPosMore.second << std::endl;
   if ((newPosMore.second * 18 + newPosMore.first) >= 0
      && newPosMore.first >= 0 && newPosMore.first <= 18
      && newPosMore.second >= 0 && newPosMore.second <= 18
      && this->_ruler.goban_test[newPosMore.second * 19 + newPosMore.first] == 0)
      {
         PlayAt(newPosMore);
         return 1;
      }
   else if ((newPosLess.second * 18 + newPosLess.first) >= 0
      && newPosLess.first >= 0 && newPosLess.first <= 18
      && newPosLess.second >= 0 && newPosLess.second <= 18
      &&this->_ruler.goban_test[newPosLess.second * 19 + newPosLess.first] == 0)
      {
         PlayAt(newPosLess);
         return 1;
      }
   else
      return -1;
}

int  AI::ContinueThisChoice(CHOICEELEM elem)
{
   std::pair<int, int>  newPosLess(ChangePosRet(elem.positions[0].first, elem.positions[0].second, elem.dir, 1));
   std::pair<int, int>  newPosMore(ChangePosRet(elem.positions[1].first, elem.positions[1].second, elem.dir, 0));

   std::pair<int, int>  newPosLess2(ChangePosRet(elem.positions[0].first, elem.positions[0].second, elem.dir, 2));
   std::pair<int, int>  newPosMore2(ChangePosRet(elem.positions[1].first, elem.positions[1].second, elem.dir, -1));

   // std::cout << "DIR === " << elem.dir << std::endl;
   // std::cout << "Coo des vector x1 = " << newPosLess.first << " y1 = " << newPosLess.second << "\tx2 = " << newPosMore.first << " y2 = " << newPosMore.second << std::endl;
   // std::cout << "Coo des vector x1 = " << newPosLess2.first << " y1 = " << newPosLess2.second << "\tx2 = " << newPosMore2.first << " y2 = " << newPosMore2.second << std::endl;
   // if (!(newPosMore.first < 0 || newPosMore.first > 18)
   if ((this->_ruler.goban_test[newPosLess.second * 19 + newPosLess.first] != 0
      || this->_ruler.goban_test[newPosMore.second * 19 + newPosMore.first] != 0))
   {
      // if (elem.nb == 2 || elem.nb == 5)
      // {
         if (this->_ruler.goban_test[newPosLess.second * 19 + newPosLess.first] == 0
            && (newPosLess.second * 18 + newPosLess.first) >= 0)
         {
            PlayAt(newPosLess);
            return 1;
         }
         else if (this->_ruler.goban_test[newPosMore.second * 19 + newPosMore.first] == 0
            && (newPosMore.second * 18 + newPosMore.first) >= 0)
         {
            PlayAt(newPosMore);
            return 1;
         }
      // }
      return -1;
   }
   // std::cout << "J'ai passé le IF" << std::endl;
   // std::cout << this->_ruler.goban_test[newPosLess.second * 19 + newPosLess.first] << "\t"\
   // << this->_ruler.goban_test[newPosMore.second * 19 + newPosMore.first] << std::endl;
   // if (!(newPosMore2.first < 0 || newPosMore2.first > 18)
   // else if (!(newPosMore2.first < 0 || newPosMore2.first > 18)
   else if (this->_ruler.goban_test[newPosLess.second * 19 + newPosLess.first] == 0
      && this->_ruler.goban_test[newPosMore.second * 19 + newPosMore.first] == 0)
   {
      if ((this->_ruler.goban_test[newPosLess2.second * 19 + newPosLess2.first] == 0
         || this->_ruler.goban_test[newPosLess2.second * 19 + newPosLess2.first] == 2)
         && (newPosLess.second * 18 + newPosLess.first) >= 0)
      {
         PlayAt(newPosLess);
         return 1;
      }
      else if ((this->_ruler.goban_test[newPosMore2.second * 19 + newPosMore2.first] == 0
         || this->_ruler.goban_test[newPosMore2.second * 19 + newPosMore2.first] == 0)
         && (newPosMore.second * 18 + newPosMore.first) >= 0)
      {
         PlayAt(newPosMore);
         return 1;
      }
      return -1;
   }
   return -1;
   // std::cout << "J'ai passé le ELSEIF" << std::endl;
}

void  AI::PlayAt(std::pair<int, int> coo)
{
   _toReturn = std::make_pair(coo.first, coo.second);
   _sprite_Gwhite.setOrigin(25,25);
   _sprite_Gwhite.setPosition(coo.first * 50, coo.second * 50);
   this->_ruler.AddSpriteToVector(_sprite_Gwhite);
}


void  AI::TakeBetterChoice()
{
   int   nb = 0;

   // std::cout << "Vector SIZE ==== " << _vChoiceElem.size() << " Vector[0].nb = " << _vChoiceElem[0].nb << " Color = " << _vChoiceElem[0].color << std::endl;
   for (auto &elem : _vChoiceElem)
   {
      if (elem.color == 2)
         nb = ContinueThisChoice(elem);
      else if (elem.color == 1)
         nb = StoleThisChoice(elem);
      if (nb == 1)
         return;
   }
   PlayByDefault();
}

int        AI::CheckDirForFutur(int &x, int &y)
{
   int tmpX(x), tmpY(y), dir(0), nb(0);
   std::vector<std::pair<int, int> > positions;

   while (dir < 8)
   {
      this->ChangePos2(tmpX, tmpY, dir);
      while (tmpX > 0 && tmpX < 19 && tmpY > 0 && tmpY < 19
         && this->_ruler.CheckCase(tmpX, tmpY, 2) == 2)
      {
         positions.push_back(std::make_pair(tmpX, tmpY));
         this->ChangePos2(tmpX, tmpY, dir);
      }
      if (positions.size() >= 3)
      {
         this->ChangePos2(x, y, dir);
         return 0;
      }
      positions.clear();
      tmpX = x;
      tmpY = y;
      ++dir;
   }
   return -1;
}

void                 AI::PlayByDefault()
{
   int               x(0), y(0), dir(0);

   // std::cout << "Je joue par défaut" << std::endl;
   for (auto &elem : this->_ruler.goban_test)
   {
      if (elem == 2 && this->CheckDirForFutur(x, y) == 0)
      {
         std::pair<int, int>  coo(x, y);
         this->PlayAt(coo);
         return;
      }
      x++;
      if (x == 19)
      {
         x = 0;
         y++;
      }
   }
}

std::pair<int, int>  AI::Play(int Round)
{
   if (Round > 1 && _vChoiceElem.size() > 0)
      TakeBetterChoice();
   else if (Round > 1)
      PlayByDefault();
   return _toReturn;
}

void  AI::displayTab()
{
   int   x(0);

   std::cout << "Tab : " << std::endl;;
   for (auto elem : this->_ruler.goban_test)
   {
      std::cout << elem;
      if (x >= 18)
      {
         x = -1;
         std::cout << std::endl;
      }
      x++;
   }
   std::cout << std::endl;
}

void  AI::FirstMove()
{
   int   x(0), y(0), i(0);

   for (auto &elem : this->_ruler.goban_test)
   {
      if (elem == 1)
      {
         // std::cout << "XXXX = " << x << "\tYYYY = " << y << std::endl;
         if (x == 18 && y == 18)
         {
            _sprite_Gwhite.setOrigin(25,25);
            _sprite_Gwhite.setPosition(50, 50);
            _oldPos = std::make_pair(50, 50);
            _toReturn = std::make_pair(1, 1);
            this->_ruler.AddSpriteToVector(_sprite_Gwhite);
            return;
         }
         _sprite_Gwhite.setOrigin(25,25);
         _sprite_Gwhite.setPosition(x * 50 + 50, y * 50);
         _oldPos = std::make_pair(x * 50 + 50, y * 50);
         _toReturn = std::make_pair(x + 1, y);
         this->_ruler.AddSpriteToVector(_sprite_Gwhite);
         return;
      }
      x++;
      if (x == 19)
      {
         x = 0;
         y++;
      }
   }
}
