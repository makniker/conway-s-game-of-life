#ifndef CELL_HPP
#define CELL_HPP

namespace conway
{
  class Cell
  {
  public:
    Cell();
    ~Cell() = default;
    void destroy();
    void revive();
    bool isAlive_;
  };
}

#endif
