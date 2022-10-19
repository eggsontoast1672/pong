#pragma once

#include <raylib.h>

#include "paddle.h"

enum LastScored {
  Computer,
  None,
  Player,
};

class Ball {
private:
  Vector2 position;

  LastScored last_scored = None;
  Vector2 velocity = {(float)BALL_VELOCITY_INITIAL,
                      (float)BALL_VELOCITY_INITIAL};

  void reset();

public:
  Ball(const Vector2 &position);

  void draw() const;
  void update(const Paddle &player, const Paddle &computer);

  LastScored get_last_scored();
};
