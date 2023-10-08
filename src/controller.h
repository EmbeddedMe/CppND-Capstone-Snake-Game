#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "food.h"

class Controller {
 public:
  void HandleInput(bool &running, Food &food, bool &resetGame) const;

 private:
  void ChangeDirection(Food &food, Food::Direction input) const;

};

#endif