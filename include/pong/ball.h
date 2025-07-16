#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable {
public:
  Ball();

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void update(const Paddle &player, const Paddle &computer);

  LastScored get_last_scored();

private:
  sf::CircleShape m_shape{BALL_RADIUS};

  Vector2 position;

  LastScored last_scored = None;
  Vector2 velocity = {(float)BALL_VELOCITY_INITIAL,
                      (float)BALL_VELOCITY_INITIAL};


  void reset();
};
