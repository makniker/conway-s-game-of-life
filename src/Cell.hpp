#ifndef CELL_HPP
#define CELL_HPP

#include <iosfwd>
#include <ostream>

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
    friend std::ostream &operator<<(std::ostream &out, const Cell &cell);

  private:
    State state_;
  };

  std::ostream &operator<<(std::ostream &out, const Cell &cell);
}

#endif
