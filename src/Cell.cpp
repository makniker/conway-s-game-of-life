#include "Cell.hpp"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

conway::Cell::Cell()
{
  srand(time(0));
  int n = rand();
  if (n % 2 == 1)
  {
    isAlive_ = 0;
  }
  else
  {
    isAlive_ = 1;
  }
}

void conway::Cell::destroy()
{
  isAlive_ = false;
}

void conway::Cell::revive()
{
  isAlive_ = true;
}
