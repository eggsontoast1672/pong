#include "paddle.h"

#include <raylib.h>

#include "constants.h"

Paddle::Paddle(const Vector2 &position, int up_key, int down_key)
    : position(position),
      up_key(up_key),
      down_key(down_key) {
}

void Paddle::draw() const {
  DrawRectangleV(position, {PADDLE_WIDTH, PADDLE_HEIGHT}, WHITE);
}

void Paddle::handle_input() {
  if (IsKeyDown(up_key)) {
    position.y -= PADDLE_VELOCITY;
  }
  if (IsKeyDown(down_key)) {
    position.y += PADDLE_VELOCITY;
  }
}

void Paddle::update() {
  if (position.y < 0) {
    position.y = 0;
  }
  if (position.y + PADDLE_HEIGHT > SCREEN_HEIGHT) {
    position.y = SCREEN_HEIGHT - PADDLE_HEIGHT;
  }
}

bool Paddle::is_colliding_with_circle(const Vector2 &center,
                                      float radius) const {
  return CheckCollisionCircleRec(
      center, radius, {position.x, position.y, PADDLE_WIDTH, PADDLE_HEIGHT});
}