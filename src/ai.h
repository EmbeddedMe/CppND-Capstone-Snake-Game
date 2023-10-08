#ifndef AI_H
#define AI_H

#include "game.h"

class AI {
public:
  void MoveTowardsFood(Snake &snake, Food food);
};

#endif