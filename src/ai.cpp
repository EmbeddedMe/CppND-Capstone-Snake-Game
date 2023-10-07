#include "ai.h"

void AI::MoveTowardsFood(Snake& snake, SDL_Point food) {

  // Get current head position
  int headX = snake.head_x; 
  int headY = snake.head_y;

  // Calculate direction towards food
  Snake::Direction direction;
  if (food.x > headX) {
    direction = Snake::Direction::kRight; 
  } else if (food.x < headX) {
    direction = Snake::Direction::kLeft;
  } else if (food.y > headY) {
    direction = Snake::Direction::kDown;
  } else if (food.y < headY) {
    direction = Snake::Direction::kUp;
  }

  // Set snake direction
  snake.direction = direction;

}