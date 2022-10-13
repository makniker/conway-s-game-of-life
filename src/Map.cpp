#include "Map.hpp"
#include "Cell.hpp"
#include <ostream>
#include <iostream>
#include <conio.h>

conway::Map::Map(std::size_t height, std::size_t width) : height_(height), width_(width), map_(height_)
{
  for (size_t i = 0; i < height_; i++)
  {
    std::vector< Cell > w(width_, Cell());
    map_[i] = w;
  }
}

std::size_t conway::Map::getNeighbours(const Cell &) const
{
  return 2;
}

void conway::Map::update()
{
  std::vector< std::vector< Cell> > newMap(height_);
  for (size_t i = 0; i < height_; i++)
  {
    std::vector<Cell> w(width_, Cell());
    newMap[i] = w;
  }
  for (size_t i = 0; i < height_; i++)
  {
    for (size_t j = 0; j < width_; j++)
    {
      if (getNeighbours(map_[i][j]) == 3 && !map_[i][j].isAlive_)
      {
        map_[i][j].revive();
      }
      else if (getNeighbours(map_[i][j]) == 3 || getNeighbours(map_[i][j]) == 2)
      {
        map_[i][j].revive();
      }
      else
      {
        map_[i][j].destroy();
      }
    }
  }
}

std::ostream &conway::operator<<(std::ostream & out, const Map & map)
{
  for (size_t i = 0; i < map.height_; i++)
  {
    for (size_t j = 0; j < map.width_; j++)
    {
      out << map.map_[i][j].isAlive_;
    }
    out << "\n";
  }
  return out;
}
