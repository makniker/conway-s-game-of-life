#ifndef CELL_HPP
#define CELL_HPP

#include <iosfwd>

namespace conway
{
  enum class State
  {
    Dead,
    Alive
  };

  struct Cell
  {
  public:
    Cell();
    Cell(char);
    ~Cell() = default;
    void destroy();
    void revive();
    State getState() const;
    friend std::ostream &conway::operator<<(std::ostream &out, const Cell &cell);

  private:
    State state;
  };

  std::ostream &conway::operator<<(std::ostream &out, const Cell &cell);
}

#endif
