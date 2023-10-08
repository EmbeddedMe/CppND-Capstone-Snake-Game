#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)), food(grid_width, grid_height) {}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration, AI &ai) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input
    controller.HandleInput(running, food, resetGame);
    
    // Get automated control input for snake
    ai.MoveTowardsFood(snake, food);
    
    // Update, Render - the main game loop.
    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count, GetSpeed());
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update() {
  
  if(resetGame){
    snake.Reset();
    score = 0;
    resetGame = false;
  }
  
  if (!snake.alive) return;

  // button.Update();
  food.Update();
  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  int newFood_x = static_cast<int>(food.x);
  int newFood_y = static_cast<int>(food.y);

  // Check if there's food over here
  if (newFood_x == new_x && newFood_y == new_y) {
    score++;
    
    // Get a new x and y for food placement
    int rand_x, rand_y;
    while (true) {
      rand_x = random_w(engine);
      rand_y = random_h(engine);
      // Check that the location is not occupied by a snake item before placing
      // food.
      if (!snake.SnakeCell(rand_x, rand_y)) {
        break;
      }
    }
    food.NewFood(rand_x, rand_y);
    
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.ChangeSpeed(snake.speed += 0.02);
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
float Game::GetSpeed() const { return snake.speed; }