#ifndef FOOD_H
#define FOOD_H

#include <vector>
#include <random>
#include "snake.h"
#include "SDL.h"

class Food {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Food(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        x(grid_width / 3),
        y(grid_height / 3) {}
  void Update();
  
  void NewFood(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  float x;
  float y;

 private:
  int grid_width;
  int grid_height;
  
  std::random_device randEng;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
};

#endif