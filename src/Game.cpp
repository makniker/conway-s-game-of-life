#include "Game.hpp"

#include <iostream>
#include <thread>
#include <chrono>

conway::Game::Game():
  map_()
{
}

void conway::Game::run()
{
  using namespace std::chrono_literals;
  auto start = std::chrono::high_resolution_clock::now();
  int i = 0;
  while (i < 10)
  {
    map_.update();
    std::cout << map_;
    std::this_thread::sleep_for(500ms);
    system("cls");
    ++i;
  }
}