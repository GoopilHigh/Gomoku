#include "../Headers/Ruler.hpp"

int         Ruler::CheckCase(int oldX, int oldY, int color)
{
   if (goban_test[oldY * 19 + oldX] == 0)
      return 2;
   if (goban_test[oldY * 19 + oldX] != color)
      return 0;
   return 1;
}

int         Ruler::CheckLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max)
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX--;
   }
   return 1;
}

int         Ruler::CheckNLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max)
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX--;
   }
   return 1;
}

int         Ruler::CheckXLeft(int oldX, int oldY, int color)
{
   int      i = 0;

   while (goban_test[oldY * 19 + oldX] == color)
   {
      oldX--;
      i++;
      if (oldX == 0)
         return i - 1;
   }
   return i - 1;
}

int         Ruler::CheckRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max))
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX++;
   }
   return 1;
}

int         Ruler::CheckNRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max))
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX++;
   }
   return 1;
}

int         Ruler::CheckXRight(int oldX, int oldY, int color)
{
   int      i = 0;

   while (goban_test[oldY * 19 + oldX] == color)
   {
      oldX++;
      i++;
      if (oldX == 19)
         return i - 1;
   }
   return i - 1;
}

int         Ruler::CheckUp(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldY < max)
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldY--;
   }
   return 1;
}

int         Ruler::CheckNUp(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldY < max)
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldY--;
   }
   return 1;
}

int         Ruler::CheckXUp(int oldX, int oldY, int color)
{
   int      i = 0;

   while (goban_test[oldY * 19 + oldX] == color)
   {
      oldY++;
      i++;
      if (oldY == 0)
         return i - 1;
   }
   return i - 1;
}

int         Ruler::CheckDown(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldY++;
   }
   return 1;
}

int         Ruler::CheckNDown(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldY++;
   }
   return 1;
}

int         Ruler::CheckXDown(int oldX, int oldY, int color)
{
   int      i = 0;

   while (goban_test[oldY * 19 + oldX] == color)
   {
      oldY++;
      i++;
      if (oldY == 19)
         return i - 1;
   }
   return i - 1;
}


int         Ruler::CheckUpLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max || oldY < max)
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX--;
      oldY--;
   }
   return 1;
}

int         Ruler::CheckNUpLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max || oldY < max)
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX--;
      oldY--;
   }
   return 1;
}

int         Ruler::CheckXUpLeft(int oldX, int oldY, int color)
{
   int      i = 0;

   while (goban_test[oldY * 19 + oldX] == color)
   {
      oldX--;
      oldY--;
      i++;
      if (oldY == 0 || oldX == 0)
         return i - 1;
   }
   return i - 1;
}

int         Ruler::CheckUpRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max) || oldY < max)
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX++;
      oldY--;
   }
   return 1;
}

int         Ruler::CheckNUpRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max) || oldY < max)
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX++;
      oldY--;
   }
   return 1;
}

int         Ruler::CheckXUpRight(int oldX, int oldY, int color)
{
   int      i = 0;

   while (goban_test[oldY * 19 + oldX] == color)
   {
      oldX++;
      oldY--;
      i++;
      if (oldY == 0 || oldX == 19)
         return i - 1;
   }
   return i - 1;
}

int         Ruler::CheckDownLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max || oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX--;
      oldY++;
   }
   return 1;
}

int         Ruler::CheckNDownLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max || oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX--;
      oldY++;
   }
   return 1;
}

int         Ruler::CheckXDownLeft(int oldX, int oldY, int color)
{
   int      i = 0;

   while (goban_test[oldY * 19 + oldX] == color)
   {
      oldX--;
      oldY++;
      i++;
      if (oldY == 19 || oldX == 0)
         return i - 1;
   }
   return i - 1;
}

int         Ruler::CheckDownRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max) || oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX++;
      oldY++;
   }
   return 1;
}

int         Ruler::CheckNDownRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max) || oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX++;
      oldY++;
   }
   return 1;
}

int         Ruler::CheckXDownRight(int oldX, int oldY, int color)
{
   int      i = 0;

   while (goban_test[oldY * 19 + oldX] == color)
   {
      oldX++;
      oldY++;
      i++;
      if (oldY == 19 || oldX == 19)
         return i - 1;
   }
   return i - 1;
}


void        Ruler::MoveToEndLine(int *oldX, int *oldY, int color)
{
   int      res = 0;

   if ((res = CheckXLeft(*oldX, *oldY, color)) > 0)
      *oldX = *oldX - res;
   else if ((res = CheckXRight(*oldX, *oldY, color)) > 0)
      *oldX = *oldX + res;
   else if ((res = CheckXUp(*oldX, *oldY, color)) > 0)
      *oldY = *oldY - res;
   else if ((res = CheckXDown(*oldX, *oldY, color)) > 0)
      *oldY = *oldY + res;
   else if ((res = CheckXUpLeft(*oldX, *oldY, color)) > 0)
   {
      *oldX = *oldX - res;
      *oldY = *oldY - res;
   }
   else if ((res = CheckXUpRight(*oldX, *oldY, color)) > 0)
   {
      *oldX = *oldX + res;
      *oldY = *oldY - res;
   }
   else if ((res = CheckXDownLeft(*oldX, *oldY, color)) > 0)
   {
      *oldX = *oldX - res;
      *oldY = *oldY + res;
   }
   else if ((res = CheckXDownRight(*oldX, *oldY, color)) > 0)
   {
      *oldX = *oldX + res;
      *oldY = *oldY + res;
   }
}

void        Ruler::Remove2(int color)
{
   int y = 0;

   for (auto &elem : to_remove)
   {
      int i = 0;
      int *nb = 0;
      for (auto &sprite : this->_goban_tab)
      {
         sf::Vector2f sprite_co = sprite.getPosition();
         int   newX = static_cast<int>(sprite_co.x) / 50;
         int   newY = static_cast<int>(sprite_co.y) / 50;
         if (newX == elem.first && newY == elem.second)
         {
            this->_goban_tab.erase(this->_goban_tab.begin() + i);
            to_remove.erase(to_remove.begin() + y);
            goban_test[newY * 19 + newX] = 0;
            nb = nb_win_stone.data();
            if (color == 1)
               nb_win_stone[1]++;
               // nb[0] = nb[0] + 1;
            else
               nb_win_stone[0]++;

               // nb[1] = nb[1] + 1;
            // nb_win_stone[0] = nb[0];
            // nb_win_stone[1] = nb[1];
         }
         i++;
      }
      y++;
   }
   std::cout << "Nombre de pierre gagnée par l'équipe " << color << " == " << nb_win_stone[0] \
   << "\tNombre de pierre gagnée par l'équipe adverse == " << nb_win_stone[1] << std::endl;
}

void        Ruler::Remove5(int color)
{
   for (auto &elem : to_remove)
   {
      int i = 0;
      int *nb = 0;
      for (auto &sprite : this->_goban_tab)
      {
         sf::Vector2f sprite_co = sprite.getPosition();
         int   newX = static_cast<int>(sprite_co.x) / 50;
         int   newY = static_cast<int>(sprite_co.y) / 50;
         if (newX == elem.first && newY == elem.second)
         {
            goban_test[newY * 19 + newX] = 0;
            nb = nb_win_stone.data();
            if (color == 1)
               nb_win_stone[1]++;
            else
               nb_win_stone[0]++;
            this->_goban_tab.erase(this->_goban_tab.begin() + i);
         }
         i++;
      }
   }
   std::cout << "Nombre de pierre gagnée par l'équipe " << color << " == " << nb_win_stone[0] \
   << "\tNombre de pierre gagnée par l'équipe adverse == " << nb_win_stone[1] << std::endl;
}

int         Ruler::CheckFor2CatchPatern(int oldX, int oldY, int color)
{
   if ((CheckNLeft(oldX - 1, oldY, color, 2) == 1 && CheckCase(oldX - 3, oldY, color) == 1)
      || (CheckNRight(oldX + 1, oldY, color, 2) == 1 && CheckCase(oldX + 3, oldY, color) == 1)
      || (CheckNUp(oldX, oldY - 1, color, 2) == 1 && CheckCase(oldX, oldY - 3, color) == 1)
      || (CheckNDown(oldX, oldY + 1, color, 2) == 1 && CheckCase(oldX, oldY + 3, color) == 1)
      || (CheckNUpLeft(oldX - 1, oldY - 1, color, 2) == 1 && CheckCase(oldX - 3, oldY - 3, color) == 1)
      || (CheckNUpRight(oldX + 1, oldY - 1, color, 2) == 1 && CheckCase(oldX + 3, oldY - 3, color) == 1)
      || (CheckNDownLeft(oldX - 1, oldY + 1, color, 2) == 1 && CheckCase(oldX - 3, oldY + 3, color) == 1)
      || (CheckNDownRight(oldX + 1, oldY + 1, color, 2) == 1  && CheckCase(oldX + 3, oldY + 3, color) == 1))
      {
            Remove2(color);
            return 1;
      }
   return 0;
}

int         Ruler::CheckFor2Catch(const int &Round)
{
   int      color = 0;
   int      x = 0;
   int      y = 0;

   if (Round % 2 == 1)
      color = 1;
   else
      color = 2;
   sf::Sprite  mySprite(this->_goban_tab.back());
   sf::Vector2f   spriteCo(mySprite.getPosition());
   for (auto &elem : goban_test)
   {
      if (spriteCo.x == (x * 50) && spriteCo.y == (y * 50) && elem == color)
      {
         if (CheckFor2CatchPatern(x, y, color) == 1)
            return 1;
      }
      x++;
      if (x >= 19)
      {
         x = 0;
         y++;
      }
   }
   return 0;

}


int         Ruler::CheckFive(int oldX, int oldY, int color)
{
   MoveToEndLine(&oldX, &oldY, color);
   // std::cout << "oldXXXX = " << oldX << std::endl;
   if (CheckLeft(oldX, oldY, color, 5) == 1 || CheckRight(oldX, oldY, color, 5) == 1
      || CheckUp(oldX, oldY, color, 5) == 1 || CheckDown(oldX, oldY, color, 5) == 1
      || CheckUpLeft(oldX, oldY, color, 5) == 1 || CheckUpRight(oldX, oldY, color, 5) == 1
      || CheckDownLeft(oldX, oldY, color, 5) == 1 || CheckDownRight(oldX, oldY, color, 5) == 1)
      {
         // std::cout << "TESTTTTTT" << std::endl;
         if (CheckFuturBroken5(oldX, oldY, color) == 1)
         {
            std::cout << "Un futur 5 cassé à été appercu !!!!!" << std::endl;
            return 0;
         }
         return 1;
      }
   else if (CheckNLeft(oldX - 1, oldY, color, 5) == 1 || CheckNRight(oldX + 1, oldY, color, 5) == 1
      || CheckNUp(oldX, oldY - 1, color, 5) == 1 || CheckNDown(oldX, oldY + 1, color, 5) == 1
      || CheckNUpLeft(oldX - 1, oldY - 1, color, 5) == 1 || CheckUpRight(oldX + 1, oldY - 1, color, 5) == 1
      || CheckNDownLeft(oldX - 1, oldY + 1, color, 5) == 1 || CheckDownRight(oldX + 1, oldY + 1, color, 5) == 1)
      {
         if (CheckBroken5(oldX, oldY, color) == 1)
         {
            std::cout << "Un 5 cassé à ete appercu !!!!!!" << std::endl;
            Remove5(color);
            return 0;
         }
      }
   return 0;
}

int         Ruler::CheckBroken3(int oldX, int oldY, int color)
{
   if (CheckLeft(oldX, oldY, color, 3) == 1 && CheckCase(oldX - 3, oldY, color)
      == 0 && CheckLeft(oldX - 4, oldY, color, 3) == 1)
      return 1;
   if (CheckRight(oldX, oldY, color, 3) == 1 && CheckCase(oldX + 3, oldY, color)
      == 0 && CheckRight(oldX + 4, oldY, color, 3) == 1)
      return 1;
   if (CheckUp(oldX, oldY, color, 3) == 1 && CheckCase(oldX, oldY - 3, color)
      == 0 && CheckUp(oldX, oldY - 4, color, 3) == 1)
      return 1;
   if (CheckDown(oldX, oldY, color, 3) == 1 && CheckCase(oldX, oldY + 3, color)
      == 0 && CheckDown(oldX, oldY + 4, color, 3) == 1)
      return 1;
   if (CheckUpLeft(oldX, oldY, color, 3) == 1 && CheckCase(oldX - 3, oldY - 3, color)
      == 0 && CheckUpLeft(oldX - 4, oldY - 4, color, 3) == 1)
      return 1;
   if (CheckUpRight(oldX, oldY, color, 3) == 1 && CheckCase(oldX + 3, oldY - 3, color)
      == 0 && CheckUpRight(oldX + 4, oldY - 4, color, 3) == 1)
      return 1;
   if (CheckDownLeft(oldX, oldY, color, 3) == 1 && CheckCase(oldX - 3, oldY + 3, color)
      == 0 && CheckDownLeft(oldX - 4, oldY + 4, color, 3) == 1)
      return 1;
   if (CheckDownRight(oldX, oldY, color, 3) == 1 && CheckCase(oldX + 3, oldY + 3, color)
      == 0 && CheckDownRight(oldX + 4, oldY + 4, color, 3) == 1)
      return 1;
   return 0;
}

int         Ruler::CheckBroken5(int oldX, int oldY, int color)
{
   std::cout << "X = " << oldX << "\tY = " << oldY << std::endl;
   if (CheckCase(oldX + 6, oldY, color) == 1 || CheckCase(oldX - 6, oldY, color) == 1
      || CheckCase(oldX, oldY + 6, color) == 1 || CheckCase(oldX, oldY - 6, color) == 1
      || CheckCase(oldX + 6, oldY + 6, color) == 1 || CheckCase(oldX + 6, oldY - 6, color) == 1
      || CheckCase(oldX - 6, oldY + 6, color) == 1 || CheckCase(oldX - 6, oldY - 6, color) == 1)
      return 1;
   return 0;
}

int         Ruler::CheckFuturBroken5(int oldX, int oldY, int color)
{
   if (CheckLeft(oldX, oldY, color, 5) == 1 && (CheckCase(oldX - 5, oldY, color) == 0
      || CheckCase(oldX + 1, oldY, color) == 0))
      return 1;
   if (CheckRight(oldX, oldY, color, 5) == 1 && (CheckCase(oldX + 5, oldY, color) == 0
      || CheckCase(oldX - 1, oldY, color) == 0))
      return 1;
   if (CheckUp(oldX, oldY, color, 5) == 1 && (CheckCase(oldX, oldY - 5, color) == 0
      || CheckCase(oldX, oldY + 1, color) == 0))
      return 1;
   if (CheckDown(oldX, oldY, color, 5) == 1 && (CheckCase(oldX, oldY + 5, color) == 0
      || CheckCase(oldX, oldY - 1, color) == 0))
      return 1;
   if (CheckUpLeft(oldX, oldY, color, 5) == 1 && (CheckCase(oldX - 5, oldY - 5, color) == 0
      || CheckCase(oldX + 1, oldY + 1, color) == 0))
      return 1;
   if (CheckUpRight(oldX, oldY, color, 5) == 1 && (CheckCase(oldX + 5, oldY - 5, color) == 0
      || CheckCase(oldX - 1, oldY + 1, color) == 0))
      return 1;
   if (CheckDownLeft(oldX, oldY, color, 5) == 1 && (CheckCase(oldX - 5, oldY + 5, color) == 0
      || CheckCase(oldX - 1, oldY + 1, color) == 0))
      return 1;
   if (CheckDownRight(oldX, oldY, color, 5) == 1 && (CheckCase(oldX + 5, oldY + 5, color) == 0
      || CheckCase(oldX - 1, oldY - 1, color) == 0))
      return 1;
   return 0;
}


int         Ruler::CheckForWinner(const int &Round)
{
   int      color = 0;
   int      x = 0;
   int      y = 0;

   if (Round % 2 == 1)
      color = 1;
   else
      color = 2;
   sf::Sprite  mySprite(this->_goban_tab.back());
   sf::Vector2f   spriteCo(mySprite.getPosition());
   for (auto &elem : goban_test)
   {
      if (spriteCo.x == (x * 50) && spriteCo.y == (y * 50) && elem == color)
      {
         if (CheckFive(x, y, color) == 1 || CheckBroken3(x, y, color) == 1)
            return 1;
      }
      x++;
      if (x >= 19)
      {
         x = 0;
         y++;
      }
   }
   return 0;
}
