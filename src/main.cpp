// TODO: Add collision detection to the ball/paddles, part 2 (maybe)
// TODO: Make ball constructor take a Vector2 instead of floats

#include <raylib.h>

#include "ball.h"
#include "constants.h"
#include "paddle.h"

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Basic Window");

  int player_score = 0;
  int computer_score = 0;

  auto ball = Ball({(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2});

  auto player = Paddle({20.0f, 20.0f}, KEY_W, KEY_S);
  auto computer = Paddle({(float)SCREEN_WIDTH - (float)PADDLE_WIDTH - 20.0f,
                          (float)SCREEN_HEIGHT - (float)PADDLE_HEIGHT - 20.0f},
                         KEY_I, KEY_K);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    //////////////////
    // Handle input //
    //////////////////

    computer.handle_input();
    player.handle_input();

    ////////////
    // Update //
    ////////////

    ball.update(player, computer);
    computer.update();
    player.update();

    switch (ball.get_last_scored()) {
    case Player:
      player_score += 1;
      break;
    case Computer:
      computer_score += 1;
      break;
    }

    //////////
    // Draw //
    //////////

    const char *player_score_text = TextFormat("%i", player_score);
    const char *computer_score_text = TextFormat("%i", computer_score);

    int player_score_width = MeasureText(player_score_text, SCORE_FONT_SIZE);

    BeginDrawing();

    ClearBackground(BLACK);

    DrawText(player_score_text, SCREEN_WIDTH / 2 - player_score_width - 20, 20,
             SCORE_FONT_SIZE, WHITE);
    DrawText(computer_score_text, SCREEN_WIDTH / 2 + 20, 20, SCORE_FONT_SIZE,
             WHITE);

    for (int i = 0; i < SCREEN_HEIGHT; i += MIDLINE_SUBSECT_LENGTH * 2) {
      DrawLine(SCREEN_WIDTH / 2, i, SCREEN_WIDTH / 2,
               i + MIDLINE_SUBSECT_LENGTH, WHITE);
    }

    ball.draw();
    computer.draw();
    player.draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
