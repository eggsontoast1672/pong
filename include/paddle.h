#pragma once

#include <raylib.h>

#include "constants.h"

class Paddle {
protected:
  Vector2 position;

  int up_key;
  int down_key;

public:
  Paddle(const Vector2 &position, int up_key, int down_key);

  void draw() const;
  void handle_input();
  void update();

  bool is_colliding_with_circle(const Vector2 &center, float radius) const;
};
