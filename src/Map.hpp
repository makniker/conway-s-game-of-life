#ifndef MAP_HPP
#define MAP_HPP

#include <iosfwd>
#include <vector>

#include "Cell.hpp"

namespace conway
{
  class Map
  {
  public:
    Map(std::size_t = 10, std::size_t = 10);
    ~Map() = default;
    void update();
    friend std::ostream &operator<<(std::ostream &, const Map &);

  private:
    std::size_t getNeighbours(const Cell&) const;

    std::size_t height_;
    std::size_t width_;
    std::vector<std::vector< Cell >> map_;
  };

  std::ostream &operator<<(std::ostream &, const Map &);
}

#endif
