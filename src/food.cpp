#include <cmath>
#include "food.h"
#include "snake.h"

void Food::Update() {}

SDL_Point Food::NewFood(Snake const &snake){
  SDL_Point food;
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}
      