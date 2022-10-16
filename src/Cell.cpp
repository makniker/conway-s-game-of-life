#include "Cell.hpp"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

conway::Cell::Cell()
{
}

conway::Cell::Cell(bool isAlive): isAlive_(isAlive)
{
}

void conway::Cell::destroy()
{
  isAlive_ = false;
}

void conway::Cell::revive()
{
  isAlive_ = true;
}
