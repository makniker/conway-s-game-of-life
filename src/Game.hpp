#ifndef GAME_HPP
#define GAME_HPP

#include <iosfwd>
#include "Map.hpp"

namespace conway
{
  class Game
  {
  public:
    Game();
    ~Game() = default;
    void run();

  private:
    conway::Map map_;
  };
}

#endif