#include "Map.hpp"
#include "Cell.hpp"
#include <ostream>
#include <iostream>
#include <conio.h>

conway::Map::Map(std::size_t height, std::size_t width) : height_(height), width_(width), map_(height_)
{
  for (size_t i = 0; i < height_; i++)
  {
    std::vector<Cell> w(width_, Cell());
    map_[i] = w;
  }
}

conway::Map::Map(std::vector<std::vector<Cell>> map, std::size_t height, std::size_t width)
    : height_(height), width_(width), map_(map)
{
}

std::size_t conway::Map::getNeighbours(std::size_t i, std::size_t j) const
{
  //написать программу по поиску соседей
  return 0;
}

void conway::Map::update()
{
  std::vector<std::vector<Cell>> newMap(height_);
  for (size_t i = 0; i < height_; i++)
  {
    std::vector<Cell> w(width_, Cell());
    newMap[i] = w;
  }
  for (size_t i = 0; i < height_; i++)
  {
    for (size_t j = 0; j < width_; j++)
    {
      if (getNeighbours(i, j) == 3 && map_[i][j].getState() == State::Dead)
      {
        newMap[i][j].revive();
      }
      else if (getNeighbours(i, j) == 3 || getNeighbours(i, j) == 2)
      {
        newMap[i][j].revive();
      }
      else
      {
        newMap[i][j].destroy();
      }
    }
  }
  map_ = newMap;
}

std::ostream &conway::operator<<(std::ostream &out, const Map &map)
{
  for (size_t i = 0; i < map.height_; i++)
  {
    for (size_t j = 0; j < map.width_; j++)
    {
      out << map.map_[i][j] << " ";
    }
    out << "\n";
  }
  return out;
}
