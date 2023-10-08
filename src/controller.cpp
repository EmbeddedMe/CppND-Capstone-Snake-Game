#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Food &food, Food::Direction input) const {
  food.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Food &food) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(food, Food::Direction::kUp);
          break;

        case SDLK_DOWN:
          ChangeDirection(food, Food::Direction::kDown);
          break;

        case SDLK_LEFT:
          ChangeDirection(food, Food::Direction::kLeft);
          break;

        case SDLK_RIGHT:
          ChangeDirection(food, Food::Direction::kRight);
          break;
      }
    } 
  }
}