#include "Game.hpp"

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

conway::Game::Game() : map_()
{
}

void conway::Game::run()
{
  printHello();
  runGameLoop();
}

void conway::Game::configureMap(const std::string &filename)
{
  std::ifstream file(filename);
  if (file.is_open())
  {
    std::size_t height;
    std::size_t width;
    file >> height >> width;
    std::string line;
    std::getline(file, line);
    std::vector<std::vector<Cell>> newMap(height);
    for (size_t i = 0; i < height; i++)
    {
      std::vector<Cell> w(width);
      std::getline(file, line);
      for (size_t j = 0; j < width; j++)
      {
        w[j] = Cell(line[j] == '1' ? true : false);
      }
      newMap[i] = w;
    }
    map_ = Map(newMap, height, width);
  }
  else
  {
    std::cerr << "wrong file";
    map_ = Map();
  }
}

void conway::Game::printHello()
{
  std::cout << "------------------------------\n";
  std::cout << "-                            -\n";
  std::cout << "-                            -\n";
  std::cout << "-                            -\n";
  std::cout << "-    WELCOME TO              -\n";
  std::cout << "-       CONWAY'S GAME        -\n";
  std::cout << "-          \"LIFE\"            -\n";
  std::cout << "-                            -\n";
  std::cout << "-                            -\n";
  std::cout << "-      Enter x to start      -\n";
  std::cout << "-                            -\n";
  std::cout << "------------------------------\n";

  while (true)
  {
    char ch;
    if (std::cin >> ch && ch == 'x')
    {
      break;
    }
  }
  system("cls");
}

void conway::Game::printMapOnConsole()
{
  std::cout << map_;
}

void conway::Game::runGameLoop()
{
  using namespace std::chrono_literals;
  auto start = std::chrono::high_resolution_clock::now();
  int numberOfMoves = 0;
  while (isRunning_)
  {
    printMapOnConsole();
    map_.update();
    std::this_thread::sleep_for(500ms);
    system("cls");
    ++numberOfMoves;
    if (numberOfMoves == 5)
    {
      isRunning_ = false;
    }
  }
}
