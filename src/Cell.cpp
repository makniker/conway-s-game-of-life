#include "Cell.hpp"

#include <ostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

conway::Cell::Cell() : state(State::Alive)
{
}

conway::Cell::Cell(char state) : state(state == 1 ? State::Alive : State::Dead)
{
}

void conway::Cell::destroy()
{
  state = State::Dead;
}

void conway::Cell::revive()
{
  state = State::Alive;
}

conway::State conway::Cell::getState() const
{
  return state;
}

std::ostream &conway::operator<<(std::ostream &out, const Cell &cell)
{
  return out << (cell.getState() == State::Alive);
}
