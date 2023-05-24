#include "diamond.h"

Vegetable::~Vegetable() {}
 
void Vegetable::Statement(void) {
  puts("This is a vegetable");
}

void Vegetable::RaisePrice(void) {
  price_ += 1337;
}

void Vegetable::GetPrice(void) {
  std::cout << "Vegie Price: " << price_ << std::endl;
}
void Vegetable::PrintName(void) {
  std::cout << "I am vegies\n";
}

Fruit::~Fruit() {}

void Fruit::Statement(void) {
  puts("This is a fruit");
}

void Fruit::RaisePrice(void) {
  price_ += 128;
}

void Fruit::GetPrice(void) {
  std::cout << "Fruit Price: " << price_ << std::endl;
}
void Fruit::PrintName(void) {
  std::cout << "I am fruit\n";
}

Tomato::Tomato() {
  // we cannot directly uses 
  Fruit::price_ = 10;
  Vegetable::price_ = 10;
}
Tomato::~Tomato() {}

void Tomato::PrintName(void) {
  std::cout << "I am tomato\n";
}

Apple::Apple() {
  price_ = 10;
}

Apple::~Apple() {}

void Apple::PrintName(void) {
  std::cout << "I am Apple\n";
}
