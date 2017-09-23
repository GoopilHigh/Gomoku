#include "../Headers/Ruler.hpp"

std::pair<int, int> Ruler::ChangePosRet(int x, int y, const int &dir, int nb)
{
  int                   i = 0;

  if (nb < 0)
  {
    nb = nb - (nb * 2);
    while (i < nb)
      {
        switch (dir)
          {
             case 0:
               ++x;
               break;
             case 1:
               --x;
               break;
             case 2:
               ++y;
               break;
             case 3:
               --y;
               break;
             case 4:
               ++x;
               ++y;
               break;
             case 5:
               --x;
               ++y;
               break;
             case 6:
               ++x;
               --y;
               break;
             case 7:
               --x;
               --y;
               break;
          }
        i++;
      }
   return (std::make_pair(x, y));
  }
  while (i < nb)
    {
      switch (dir)
        {
          case 0:
            --x;
            break;
          case 1:
            ++x;
            break;
          case 2:
            --y;
            break;
          case 3:
            ++y;
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
      i++;
    }
  return (std::make_pair(x, y));
}


int         Ruler::TryNonCatch(int x, int y, int color, int dir1, int dir2)
{
   int      dir(0), tmpX(x), tmpY(y);
   while (dir < 8)
   {
      if (dir != dir1 && dir != dir2)
      {
         ChangePos(tmpX, tmpY, dir);
         if (CheckCase(tmpX, tmpY, color) == 1)
         {
            ChangePos(tmpX, tmpY, dir);
            if (CheckCase(tmpX, tmpY, color) == 0)// && CheckCase(tmpX, tmpY, color) != 2)
            {
               std::pair<int, int> coo(ChangePosRet(tmpX, tmpY, dir, -3));
               if (CheckCase(coo.first, coo.second, color) == 2)
                  return -1;
            }
         }

      }
      tmpX = x;
      tmpY = y;
      ++dir;
   }
   return 0;
}

bool        Ruler::CheckPos(const int &x, const int &y) {
  if (x < 0 || x > 19 || y < 0 || y > 19)
    return false;
  return true;
}

int         Ruler::CheckCase(int oldX, int oldY, int color)
{
  if (oldX < 0 || oldX > 19 || oldY < 0 || oldY > 19)
    return 0;
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
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX--;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 2;
   return 1;
}

int         Ruler::CheckNCLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max)
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color || TryNonCatch(oldX, oldY, color, 0, 1) == -1)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX--;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 2;
   return 1;
}

int         Ruler::CheckNLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max)
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX--;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return 1;
}

int         Ruler::CheckXLeft(int oldX, int oldY, int color)
{
   int      i = 0;

  if (oldX < 0 || oldX > 19 || oldY < 0 || oldY > 19)
      return 0;
   while (this->CheckPos(oldX, oldY) && goban_test[oldY * 19 + oldX] == color)
   {
      oldX--;
      i++;
      if (oldX == 0)
         return i - 1;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return i - 1;
}

int         Ruler::CheckRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX++;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 3;
   return 1;
}

int         Ruler::CheckNCRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color || TryNonCatch(oldX, oldY, color, 0, 1) == -1)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX++;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 3;
   return 1;
}

int         Ruler::CheckNRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX++;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return 1;
}

int         Ruler::CheckXRight(int oldX, int oldY, int color)
{
   int      i = 0;

   if (oldX < 0 || oldX > 19 || oldY < 0 || oldY > 19)
    return 0;
   while (this->CheckPos(oldX, oldY) && goban_test[oldY * 19 + oldX] == color)
   {
      oldX++;
      i++;
      if (oldX == 19)
         return i - 1;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return i - 1;
}

int         Ruler::CheckUp(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldY < max)
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldY--;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 0;
   return 1;
}

int         Ruler::CheckNCUp(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldY < max)
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color || TryNonCatch(oldX, oldY, color, 2, 3) == -1)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldY--;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 0;
   return 1;
}

int         Ruler::CheckNUp(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldY < max)
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldY--;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return 1;
}

int         Ruler::CheckXUp(int oldX, int oldY, int color)
{
   int      i = 0;

   if (oldX < 0 || oldX > 19 || oldY < 0 || oldY > 19)
    return 0;
   while (this->CheckPos(oldX, oldY) && goban_test[oldY * 19 + oldX] == color)
   {
      oldY--;
      i++;
      if (oldY == 0)
         return i - 1;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return i - 1;
}

int         Ruler::CheckDown(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldY++;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 1;
   return 1;
}

int         Ruler::CheckNCDown(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color || TryNonCatch(oldX, oldY, color, 2, 3) == -1)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldY++;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 1;
   return 1;
}

int         Ruler::CheckNDown(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldY++;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return 1;
}

int         Ruler::CheckXDown(int oldX, int oldY, int color)
{
   int      i = 0;

   if (oldX < 0 || oldX > 19 || oldY < 0 || oldY > 19)
    return 0;
   while (this->CheckPos(oldX, oldY) && goban_test[oldY * 19 + oldX] == color)
   {
      oldY++;
      i++;
      if (oldY == 19)
         return i - 1;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return i - 1;
}


int         Ruler::CheckUpLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max || oldY < max)
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
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
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 4;
   return 1;
}

int         Ruler::CheckNCUpLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max || oldY < max)
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color || TryNonCatch(oldX, oldY, color, 4, 7) == -1)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX--;
      oldY--;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 4;
   return 1;
}

int         Ruler::CheckNUpLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max || oldY < max)
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
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
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return 1;
}

int         Ruler::CheckXUpLeft(int oldX, int oldY, int color)
{
   int      i = 0;

   if (oldX < 0 || oldX > 19 || oldY < 0 || oldY > 19)
    return 0;
   while (this->CheckPos(oldX, oldY) && goban_test[oldY * 19 + oldX] == color)
   {
      oldX--;
      oldY--;
      i++;
      if (oldY == 0 || oldX == 0)
         return i - 1;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return i - 1;
}

int         Ruler::CheckUpRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max) || oldY < max)
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
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
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 5;
   return 1;
}

int         Ruler::CheckNCUpRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max) || oldY < max)
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color || TryNonCatch(oldX, oldY, color, 5, 6) == -1)
         return 0;
      i++;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      oldX++;
      oldY--;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 5;
   return 1;
}

int         Ruler::CheckNUpRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max) || oldY < max)
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      ++i;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      ++oldX;
      --oldY;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return 1;
}

int         Ruler::CheckXUpRight(int oldX, int oldY, int color)
{
   int      i = 0;

   if (oldX < 0 || oldX > 19 || oldY < 0 || oldY > 19)
    return 0;
   while (this->CheckPos(oldX, oldY) && goban_test[oldY * 19 + oldX] == color)
   {
      ++oldX;
      --oldY;
      ++i;
      if (oldY == 0 || oldX == 19)
         return i - 1;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return i - 1;
}

int         Ruler::CheckDownLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max || oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      ++i;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      --oldX;
      ++oldY;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 6;
   return 1;
}

int         Ruler::CheckNCDownLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max || oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color || TryNonCatch(oldX, oldY, color, 5, 6) == -1)
         return 0;
      ++i;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      --oldX;
      ++oldY;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 6;
   return 1;
}

int         Ruler::CheckNDownLeft(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX < max || oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      ++i;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      --oldX;
      ++oldY;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return 1;
}

int         Ruler::CheckXDownLeft(int oldX, int oldY, int color)
{
   int      i = 0;

   if (oldX < 0 || oldX > 19 || oldY < 0 || oldY > 19)
    return 0;
   while (this->CheckPos(oldX, oldY) && goban_test[oldY * 19 + oldX] == color)
   {
      --oldX;
      ++oldY;
      ++i;
      if (oldY == 19 || oldX == 0)
         return i - 1;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return i - 1;
}

int         Ruler::CheckDownRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max) || oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color)
         return 0;
      ++i;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      ++oldX;
      ++oldY;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 7;
   return 1;
}

int         Ruler::CheckNCDownRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max) || oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] != color || TryNonCatch(oldX, oldY, color, 4, 7) == -1)
         return 0;
      ++i;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      ++oldX;
      ++oldY;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   dir = 7;
   return 1;
}

int         Ruler::CheckNDownRight(int oldX, int oldY, int color, int max)
{
   int      i = 0;

   if (oldX > (19 - max) || oldY > (19 - max))
      return 0;
   to_remove.clear();
   while (this->CheckPos(oldX, oldY) && i < max)
   {
      if (goban_test[oldY * 19 + oldX] == color || goban_test[oldY * 19 + oldX] == 0)
         return 0;
      ++i;
      std::pair<int, int> newElem;
      newElem = std::make_pair(oldX, oldY);
      to_remove.push_back(newElem);
      ++oldX;
      ++oldY;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return 1;
}

int         Ruler::CheckXDownRight(int oldX, int oldY, int color)
{
   int      i = 0;

   if (oldX < 0 || oldX > 19 || oldY < 0 || oldY > 19)
    return 0;
   while (this->CheckPos(oldX, oldY) && goban_test[oldY * 19 + oldX] == color)
   {
      ++oldX;
      ++oldY;
      ++i;
      if (oldY == 19 || oldX == 19)
         return i - 1;
   }
   if (!this->CheckPos(oldX, oldY))
    return 0;
   return i - 1;
}


void        Ruler::MoveToEndLine(int *oldX, int *oldY, int color)
{
   int      res = 0;

   if ((res = CheckXLeft(*oldX, *oldY, color)) >= 2 && res < 5)
      *oldX = *oldX - res;
   else if ((res = CheckXRight(*oldX, *oldY, color)) >= 2 && res < 5)
      *oldX = *oldX + res;
   else if ((res = CheckXUp(*oldX, *oldY, color)) >= 2 && res < 5)
      *oldY = *oldY - res;
   else if ((res = CheckXDown(*oldX, *oldY, color)) >= 2 && res < 5)
      *oldY = *oldY + res;
   else if ((res = CheckXUpLeft(*oldX, *oldY, color)) >= 2 && res < 5)
   {
      *oldX = *oldX - res;
      *oldY = *oldY - res;
   }
   else if ((res = CheckXUpRight(*oldX, *oldY, color)) >= 2 && res < 5)
   {
      *oldX = *oldX + res;
      *oldY = *oldY - res;
   }
   else if ((res = CheckXDownLeft(*oldX, *oldY, color)) >= 2 && res < 5)
   {
      *oldX = *oldX - res;
      *oldY = *oldY + res;
   }
   else if ((res = CheckXDownRight(*oldX, *oldY, color)) >= 2 && res < 5)
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
            else
               nb_win_stone[0]++;
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
   int      i(0);

   if ((CheckNLeft(oldX - 1, oldY, color, 2) == 1 && CheckCase(oldX - 3, oldY, color) == 1))
   {
         Remove2(color);
         ++i;
   }
   if ((CheckNRight(oldX + 1, oldY, color, 2) == 1 && CheckCase(oldX + 3, oldY, color) == 1))
   {
         Remove2(color);
         ++i;
   }
   if ((CheckNUp(oldX, oldY - 1, color, 2) == 1 && CheckCase(oldX, oldY - 3, color) == 1))
   {
         Remove2(color);
         ++i;
   }
   if ((CheckNDown(oldX, oldY + 1, color, 2) == 1 && CheckCase(oldX, oldY + 3, color) == 1))
   {
         Remove2(color);
         ++i;
   }
   if ((CheckNUpLeft(oldX - 1, oldY - 1, color, 2) == 1 && CheckCase(oldX - 3, oldY - 3, color) == 1))
   {
         Remove2(color);
         ++i;
   }
   if ((CheckNUpRight(oldX + 1, oldY - 1, color, 2) == 1 && CheckCase(oldX + 3, oldY - 3, color) == 1))
   {
         Remove2(color);
         ++i;
   }
   if ((CheckNDownLeft(oldX - 1, oldY + 1, color, 2) == 1 && CheckCase(oldX - 3, oldY + 3, color) == 1))
   {
         Remove2(color);
         ++i;
   }
   if ((CheckNDownRight(oldX + 1, oldY + 1, color, 2) == 1  && CheckCase(oldX + 3, oldY + 3, color) == 1))
   {
         Remove2(color);
         ++i;
   }
   if (i > 0)
      return 1;
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
   if (CheckNCLeft(oldX, oldY, color, 5) == 1 || CheckNCRight(oldX, oldY, color, 5) == 1
      || CheckNCUp(oldX, oldY, color, 5) == 1 || CheckNCDown(oldX, oldY, color, 5) == 1
      || CheckNCUpLeft(oldX, oldY, color, 5) == 1 || CheckNCUpRight(oldX, oldY, color, 5) == 1
      || CheckNCDownLeft(oldX, oldY, color, 5) == 1 || CheckNCDownRight(oldX, oldY, color, 5) == 1)
      {
         // if (CheckFuturBroken5(oldX, oldY, color) == 1)
         //    return 0;
         return 1;
      }
   // else if (CheckNLeft(oldX - 1, oldY, color, 5) == 1 || CheckNRight(oldX + 1, oldY, color, 5) == 1
   //    || CheckNUp(oldX, oldY - 1, color, 5) == 1 || CheckNDown(oldX, oldY + 1, color, 5) == 1
   //    || CheckNUpLeft(oldX - 1, oldY - 1, color, 5) == 1 || CheckUpRight(oldX + 1, oldY - 1, color, 5) == 1
   //    || CheckNDownLeft(oldX - 1, oldY + 1, color, 5) == 1 || CheckDownRight(oldX + 1, oldY + 1, color, 5) == 1)
   //    {
   //       if (CheckBroken5(oldX, oldY, color) == 1)
   //       {
   //          Remove5(color);
   //          return 0;
   //       }
   //    }
   return 0;
}

int         Ruler::CheckBroken5(int oldX, int oldY, int color)
{
   if (CheckCase(oldX + 6, oldY, color) == 1 || CheckCase(oldX - 6, oldY, color) == 1
      || CheckCase(oldX, oldY + 6, color) == 1 || CheckCase(oldX, oldY - 6, color) == 1
      || CheckCase(oldX + 6, oldY + 6, color) == 1 || CheckCase(oldX + 6, oldY - 6, color) == 1
      || CheckCase(oldX - 6, oldY + 6, color) == 1 || CheckCase(oldX - 6, oldY - 6, color) == 1)
      return 1;
   return 0;
}

int         Ruler::CheckFuturBroken5(int oldX, int oldY, int color)
{
   int      test(0);
   switch (dir)
   {
      case 0:
         if (CheckUp(oldX, oldY, color, 5) == 1 && (CheckCase(oldX, oldY - 5, color) == 0
            || CheckCase(oldX, oldY + 1, color) == 0))
               test = 1;
         break;
      case 1:
         if (CheckDown(oldX, oldY, color, 5) == 1 && (CheckCase(oldX, oldY + 5, color) == 0
            || CheckCase(oldX, oldY - 1, color) == 0))
               test = 1;
         break;
      case 2:
         if (CheckLeft(oldX, oldY, color, 5) == 1 && (CheckCase(oldX - 5, oldY, color) == 0
            || CheckCase(oldX + 1, oldY, color) == 0))
               test = 1;
         break;
      case 3:
         if (CheckRight(oldX, oldY, color, 5) == 1 && (CheckCase(oldX + 5, oldY, color) == 0
            || CheckCase(oldX - 1, oldY, color) == 0))
               test = 1;
      case 4:
         if (CheckUpLeft(oldX, oldY, color, 5) == 1 && (CheckCase(oldX - 5, oldY - 5, color) == 0
            || CheckCase(oldX + 1, oldY + 1, color) == 0))
               test = 1;
         break;
      case 5:
         if (CheckUpRight(oldX, oldY, color, 5) == 1 && (CheckCase(oldX + 5, oldY - 5, color) == 0
            || CheckCase(oldX - 1, oldY + 1, color) == 0))
               test =  1;
         break;
      case 6:
         if (CheckDownLeft(oldX, oldY, color, 5) == 1 && (CheckCase(oldX - 5, oldY + 5, color) == 0
            || CheckCase(oldX - 1, oldY + 1, color) == 0))
               test = 1;
         break;
      case 7:
         if (CheckDownRight(oldX, oldY, color, 5) == 1 && (CheckCase(oldX + 5, oldY + 5, color) == 0
            || CheckCase(oldX - 1, oldY - 1, color) == 0))
               test = 1;
         break;

   }
   if (test == 1)
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
         if (CheckFive(x, y, color) == 1)
            return 1;
      }
      ++x;
      if (x >= 19)
      {
         x = 0;
         ++y;
      }
   }
   return 0;
}

/* Check Double 3 */

/* Onchange les positions en fonction de la direction */
void Ruler::ChangePos(int &x, int &y, const int &dir) {
  switch (dir) {
    case 0:
      --x;
      break;
    case 1:
      ++x;
      break;
    case 2:
      --y;
      break;
    case 3:
      ++y;
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

/* On vérifie qu'un 5 est possible
Si oui retourne true sinon false */
bool  Ruler::CheckFreeFive(const int &x, const int &y, const int &dir, const int &color) {
  int tmpX(x), tmpY(y), tmpColor;

  (color == 1) ? tmpColor = 2 : tmpColor = 1;
  if (!this->CheckPos(tmpX, tmpY))
    return false;
  if (goban_test[tmpY * 19 + tmpX] == tmpColor)
    return false;
  for (int f = 0; f < 3; ++f) {
    this->ChangePos(tmpX, tmpY, dir);
    if (!this->CheckPos(tmpX, tmpY))
      return false;
    if (goban_test[tmpY * 19 + tmpX] == tmpColor)
      return false;
  }
  return true;
}

/* On regarde si il y a un 3 autour du point en évitant la direction dir
Si oui on retourne la dir sinon - 1 */
int Ruler::CheckAround2(int &x, int &y, const int &color, const int &dir, const int i) {
  int tmpX(x), tmpY(y);

  for (int f = 0; f < 8; ++f) {
    switch (f) {
      case 0:
        x -= i;;
        break;
      case 1:
        x += i;
        break;
      case 2:
        y -= i;
        break;
      case 3:
        y += i;
        break;
      case 4:
        x -= i;
        y -= i;
        break;
      case 5:
        x += i;
        y -= i;
        break;
      case 6:
        x -= i;
        y += i;
        break;
      case 7:
        x += i;
        y += i;
        break;
    }
    if (f != dir && ((this->*this->_check[f])(x, y, color, 2)) == 1
        && this->CheckFreeFive(x, y, f, color)) {
      x = tmpX;
      y = tmpY;
      return f;
    }
    x = tmpX;
    y = tmpY;
  }
  return -1;
}

/* On vérifie si il y a deux 3 ou un 3 et un 3 cassé autour du point
Si oui on retourne true */
bool Ruler::CheckDoubleThree(const int &round, int x, int y) {
  int color, dir(-1);

  if (round % 2 == 1)
     color = 1;
  else
     color = 2;
  x = x / 5 * 0.1;
  y = y / 5 * 0.1;
  if ((dir = this->CheckAround2(x, y, color, -1, 1)) != -1) {
    if (this->CheckAround2(x, y, color, dir, 1) != -1)
      return true;
    if (this->CheckAround2(x, y, color, dir, 2) != -1)
      return true;
  }
  if ((dir = this->CheckAround2(x, y, color, -1, 2)) != -1) {
    if (this->CheckAround2(x, y, color, dir, 2) != -1)
      return true;
  }
  return false;
}
