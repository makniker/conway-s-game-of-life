#include <cstdlib>
#include <iostream>

#include "Game.hpp"

int main(int argc, char *argv[])
{
  conway::Game game;
  game.configureMap(argv[1]);
  game.run();
  return 0;
}
