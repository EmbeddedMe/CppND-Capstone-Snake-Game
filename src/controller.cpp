#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Food &food, Food::Direction input) const {
  food.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Food &food, bool &resetGame) const {
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
        case SDLK_r:
          std::cout << "Detected: KeyDown [r] -> Reset game\n";
          resetGame = true;
          break;
      }
    } else if (e.type == SDL_MOUSEBUTTONDOWN) {
      // Handle mouse events

      switch(e.button.button){
        // Decrease speed if left mouse button
        case SDL_BUTTON_LEFT:
          std::cout << "Detected: MouseButtonDown [Left] -> Decrease snake speed\n";
          food.ChangeSpeed(food.speed/=1.1);
          break;
        // Increase speed if right mouse button
        case SDL_BUTTON_RIGHT:
          std::cout << "Detected: MouseButtonDown [Right] -> Increase snake speed\n";
          food.ChangeSpeed(food.speed*=1.1);
          break;

      } 
    } 
  }
}