#include <SFML/Graphics.hpp>

#include "pong/constants.h"

int main() {
  sf::RenderWindow window{sf::VideoMode{SCREEN_WIDTH, SCREEN_HEIGHT}, "Pong"};
  window.setFramerateLimit(60);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }
}
