#include <cstdlib>
#include <iostream>

#include "Game.hpp"

int main(int argc, char *argv[])
{
  conway::Game game;
  if (argc == 2)
  {
    std::string mapPath = argv[1];
    game.configureMap(argv[1]);
  }
  game.run();
  return 0;
}
