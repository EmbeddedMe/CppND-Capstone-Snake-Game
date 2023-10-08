#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <unordered_set>
#include "SDL.h"

// Custom hash function for SDL_Point.
struct SDL_PointHash {
  std::size_t operator()(const SDL_Point& point) const {
    // Combine the x and y coordinates to generate a hash.
    return std::hash<int>()(point.x) ^ std::hash<int>()(point.y);
  }
};

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);
  void ChangeSpeed(float speed);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;
  std::unordered_set<SDL_Point, SDL_PointHash> bodySet;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif