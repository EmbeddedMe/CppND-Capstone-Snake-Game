#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::ChangeSpeed(Snake &snake, float speed) const {
  snake.speed = speed;
  std::cout << "Speed: " << speed <<std::endl;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    } else if (e.type == SDL_MOUSEBUTTONDOWN) {
      // Handle mouse events
      
      switch(e.button.button){
        // Decrease speed if left mouse button
        case SDL_BUTTON_LEFT:
          std::cout << "Detected: MouseButtonDown [Left] -> Decrease snake speed\n";
          ChangeSpeed(snake, snake.speed/=1.1);
          break;
        // Increase speed if right mouse button
        case SDL_BUTTON_RIGHT:
          std::cout << "Detected: MouseButtonDown [Right] -> Increase snake speed\n";
          ChangeSpeed(snake, snake.speed*=1.1);
          break;

      } 
    }
  }
}