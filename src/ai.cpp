#include "ai.h"

void AI::MoveTowardsFood(Snake& snake, Food &food) {

  // Get current head position
  int headX = snake.head_x; 
  int headY = snake.head_y;

  // Calculate possible directions towards food that avoid the snake body
  std::vector<Snake::Direction> directions;

  if (snake.direction != Snake::Direction::kLeft && food.x > headX && !snake.SnakeCell(headX + 1, headY)) {
    directions.push_back(Snake::Direction::kRight);
  }
  
  if (snake.direction != Snake::Direction::kRight && food.x < headX && !snake.SnakeCell(headX - 1, headY)) {  
    directions.push_back(Snake::Direction::kLeft);
  }

  if (snake.direction != Snake::Direction::kUp && food.y > headY && !snake.SnakeCell(headX, headY + 1)) {
    directions.push_back(Snake::Direction::kDown);
  }

  if (snake.direction != Snake::Direction::kDown && food.y < headY && !snake.SnakeCell(headX, headY - 1)) {
    directions.push_back(Snake::Direction::kUp);
  }

  // Select first viable direction
  if (!directions.empty()) {
      snake.direction = directions[0]; 
  } else {
    // Just go up by defaut
    snake.direction = Snake::Direction::kUp;
  }
}