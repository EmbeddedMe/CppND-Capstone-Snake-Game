#include <cmath>
#include "food.h"
#include "snake.h"

void Food::Update() {
    switch (direction) {
    case Direction::kUp:
      y -= speed;
      break;

    case Direction::kDown:
      y += speed;
      break;

    case Direction::kLeft:
      x -= speed;
      break;

    case Direction::kRight:
      x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  x = fmod(x + grid_width, grid_width);
  y = fmod(y + grid_height, grid_height);
}

void Food::NewFood(int x, int y){
  this->x = x;
  this->y = y;
  return;
}

void Food::ChangeSpeed(float speed) {
  if(this->speed > 0.5){
    this->speed = 0.5;
  } else {
    this->speed = speed;
  }
  return;
}
      