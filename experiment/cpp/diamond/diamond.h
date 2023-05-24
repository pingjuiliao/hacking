#ifndef DIAMOND_H
#define DIAMOND_H

#include <stdio.h>

#include <iostream>

/*******************************
 * Food --> Vegetable --> Tomato (Diamond) 
 *      \              /
 *       -> Fruit  ---- ---> Apple
 * 
 *
 * *************************/


class Food {
 public:
  virtual ~Food() = default;
  virtual void Statement(void) = 0;
  virtual void RaisePrice(void) = 0;
  virtual void GetPrice(void) = 0;
  virtual void PrintName(void) = 0;
 protected:
  int price_;
};

class Vegetable: public Food {
 public:
  virtual ~Vegetable();
  virtual void Statement(void);
  virtual void RaisePrice(void);
  virtual void GetPrice(void);
  virtual void PrintName(void);
};

class Fruit: public Food {
 public:
  virtual ~Fruit();
  virtual void Statement(void);
  virtual void RaisePrice(void);
  virtual void GetPrice(void);
  virtual void PrintName(void);
};

class Tomato: public Vegetable, public Fruit {
 public:
  Tomato();
  virtual ~Tomato();
  virtual void PrintName(void);
};

class Apple: public Fruit {
 public:
  Apple();
  virtual ~Apple();
  virtual void PrintName(void);
};

#endif  // DIAMOND_H
