#include "ball.h"

#include <cstdio>

#include <raylib.h>

#include "constants.h"
#include "paddle.h"

void Ball::reset() {
  position.x = (float)SCREEN_WIDTH / 2;
  position.y = (float)SCREEN_HEIGHT / 2;

  // Send the ball back towards the player who last scored
  velocity.x *= -1;
}

Ball::Ball(const Vector2 &position)
    : position(position) {
}

void Ball::draw() const {
  DrawCircleV(position, BALL_RADIUS, WHITE);
}

void Ball::update(const Paddle &player, const Paddle &computer) {
  position.x += velocity.x;
  position.y += velocity.y;

  // if (position.x - radius < 0) {
  //   position.x = radius;
  //   velocity.x *= -1;
  // }
  // if (position.x + radius > SCREEN_WIDTH) {
  //   position.x = SCREEN_WIDTH - radius;
  //   velocity.x *= -1;
  // }
  if (position.y - BALL_RADIUS < 0) {
    position.y = BALL_RADIUS;
    velocity.y *= -1;
  }
  if (position.y + BALL_RADIUS > SCREEN_HEIGHT) {
    position.y = SCREEN_HEIGHT - BALL_RADIUS;
    velocity.y *= -1;
  }

  // Check for collision with paddle. TODO: I should revisit this after I've
  // implemented the scoring system.
  if (player.is_colliding_with_circle(position, BALL_RADIUS) ||
      computer.is_colliding_with_circle(position, BALL_RADIUS)) {
    velocity.x *= -1;
  }

  // Scoring
  if (position.x + BALL_RADIUS < 0) {
    last_scored = Computer;
    reset();
  }
  if (position.x - BALL_RADIUS > SCREEN_WIDTH) {
    last_scored = Player;
    reset();
  }
}

LastScored Ball::get_last_scored() {
  LastScored result = last_scored;
  last_scored = None;
  return result;
}