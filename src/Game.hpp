#ifndef GAME_HPP
#define GAME_HPP

#include <iosfwd>
#include <string>
#include "Map.hpp"

namespace conway
{
  class Game
  {
  public:
    Game();
    ~Game() = default;
    void run();
    void configureMap(const std::string&);

  private:
    conway::Map map_;
  };
}

#endif