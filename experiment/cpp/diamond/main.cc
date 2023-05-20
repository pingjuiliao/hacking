#include <stdio.h>

#include "diamond.h"

void non_diamond(void);
void diamond(void);

int main(int argc, char** argv) {
  non_diamond();
  diamond();
}

void non_diamond() {
  Fruit* apple = new Apple();
  apple->Statement();
  
  puts("Down casting the apple"); 
  Apple* the_apple = dynamic_cast<Apple*>(apple);
  the_apple->RaisePrice();
  the_apple->GetPrice();
  apple->GetPrice();
}

void diamond() {
  puts("A fruit buffer defines tomato as a kind of fruit");
  Fruit* fruit_tomato = new Tomato();
  fruit_tomato->Statement();
  
  puts("A vegie buffer defines tomatos as a kind of vegetable");
  Vegetable* veg_tomato = dynamic_cast<Vegetable*>(fruit_tomato);
  veg_tomato->Statement();
  
  puts("Dynamic casting won't change the things");
  fruit_tomato->Statement();

  printf("veg_tomato == fruit_tomato? %p == %p\n", fruit_tomato, veg_tomato);
  fruit_tomato->RaisePrice();
  veg_tomato->RaisePrice();
  fruit_tomato->GetPrice();
  veg_tomato->GetPrice();
}
