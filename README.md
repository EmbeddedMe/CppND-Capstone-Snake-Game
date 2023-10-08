# CPPND: Capstone Snake Game - Extended

This project is based on the starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

## New Features
- Created an AI snake to chase the food while trying to avoid it's own body.
- Get user input to move the food while the snake is chasing it, including changing the speed of the food using the mousebuttons.
- Created new Food and AI classes.
- Food spawns in a new location with user control still active.
- Added functionality to reset the game using the "r" key. This resets the snake completely.
- Save last score to a file.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Rubric 
- README (All Rubric Points REQUIRED) [Completed]
- Compiling and Testing (All Rubric Points REQUIRED) [Completed]
- The project demonstrates an understanding of C++ functions and control structures. [Completed]
  - New functions were added in ai.cpp, a switch control structure was used in controller.cpp, lines 34-50.
- The project accepts user input and processes the input. [Completed]
  - controller.cpp, lines 39-55 - the user can increase and decrease the speed of the snake between it's limits using the right and left mouse buttons respectively.
- The project uses Object Oriented Programming techniques. [Completed]
  - A new AI class was created in ai.h and ai.cpp. The methodto change snake speed was removed from the controller class and implemented in the snake class - snake.cpp, lines 81-89.
- Classes encapsulate behavior. [Completed]
  - The AI class encapsulates the logic for the snake's automated movement and can easily be extended with new features.
- The project reads data from a file and process the data, or the program writes data to a file. [Completed]
  - The program saves the last game stats to a file - main.cpp, lines 26-42.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
