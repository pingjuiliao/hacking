#include <iostream>

#include <stdio.h>

class Coordinate {
 public:
  Coordinate(int x, int y, int z) {
    x_ = x; y_ = y; z_ = z;
  }
  ~Coordinate() {}
  void Show(void) const {
    printf("Coord: (%d, %d, %d)\n", x_, y_, z_);
  }
 protected:
  int x_;
  int y_;
  int z_;
};

int main(int argc, char** argv) {
  Coordinate const* a = new Coordinate(1, 2, 3);
  Coordinate const* b = new Coordinate(4, 5, 6);
  a->Show();
  b->Show();
  return 0;
}
