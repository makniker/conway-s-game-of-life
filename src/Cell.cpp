#include "Cell.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

conway::Cell::Cell() : state_(State::Dead)
{
}

conway::Cell::Cell(char state_) : state_(state_ == 1 ? State::Alive : State::Dead)
{
}

void conway::Cell::destroy()
{
  state_ = State::Dead;
}

void conway::Cell::revive()
{
  state_ = State::Alive;
}

conway::State conway::Cell::getState() const
{
  return state_;
}

std::ostream &conway::operator<<(std::ostream &out, const Cell &cell)
{
  return out << (cell.getState() == State::Alive ? 1 : 0);
}
