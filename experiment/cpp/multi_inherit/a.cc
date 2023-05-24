
#include <stdio.h>

#include <iostream>

class Particle {
 public:
  int x_;
  int y_;
  int z_;
  virtual ~Particle() = default;
  virtual void show_position(void) {
    printf("(%d, %d, %d)\n", x_, y_, z_); 
  }
  virtual void stat(void) {
    show_position();
  }
};

class Wave {
 public:
  int lambda_;
  virtual ~Wave() = default;
  virtual void show_lambda(void) {
    printf("lambda: %d\n", lambda_);
  }
  virtual void stat(void) {
    show_lambda();
  }
};


class Light: public Particle, public Wave {
 public:
  Light(int x, int y, int z, int lambda) {
    x_ = x;
    y_ = y;
    z_ = z;
    lambda_ = lambda;
  } 
  ~Light() {}
};

void breakpoint_me(void) {
  puts("brkpt me");
}

int main(int argc, char** argv) {
  Wave* wave = NULL;
  Particle* dot = NULL;
  Light* light = new Light(1, 2, 3, 4);

  printf("Light: %p\n", light);
  wave = light;
  dot = light;
  dot->show_position();
  wave->show_lambda();
  breakpoint_me();
  return 0;
}
