# include "C_tools/inc/C_tool.h"

// tmp solution
extern "C" {
# include "inc/GMRender.h"
}
//

static void debug(void) {
  static bool debug = true;
  if (debug) {
    char s[50];
    bzero(s, 50);
    snprintf(s, 50, "fps = %d", GetFPS());
    DrawText(s, 0,0, 30, WHITE);
  }
  if (IsKeyPressed(KEY_BACKSPACE)) {
    if (debug)
      debug = false;
    else
      debug = true;
  }
}

static void start(void) {
  SetTraceLogLevel(LOG_NONE);
  InitWindow(PROJECT_W, PROJECT_H, PROJECT_NAME);
  SetTargetFPS(PROJECT_FPS);
}

static void end(void) {
  CloseWindow();
}

int main(void) {
  start();
  while (!WindowShouldClose()) {
  /*
    > code here <
  */
  }
  end();
}