#include <iostream>
#include <fstream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "ai.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  AI ai;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame, ai);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  std::cout << "Final Speed: " << game.GetSpeed() << "\n";

    // Open a file for writing
    std::ofstream outputFile("game_stats.txt");

    if (outputFile.is_open()) {
        // Write game stats to file
        outputFile << "Previous Game Stats:\n";
        outputFile << "Score: " << game.GetScore() << "\n";
        outputFile << "Size: " << game.GetSize() << "\n";
        outputFile << "Final Speed: " << game.GetSpeed() << "\n";

        // Close the file
        outputFile.close();

        std::cout << "Statistics saved to 'game_stats.txt'.\n";
    } else {
        std::cerr << "Unable to open the file for writing.\n";
    }

  return 0;
}