# include "C_tools/inc/C_tool.h"
# include "inc/GMRender.h"

void debug(void) {
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

int main() {
  t_Canvas*      canvas = initCanvas();
  SetTraceLogLevel(LOG_NONE);
  InitWindow(700,700, "def game");
  SetTargetFPS(60);
  t_RenderValue  test, test2;
  test._Id = 1;
  test2._Id = 2;
  test2.Depth = 1;
  test.Depth = 2;
  for (size_t i = 0; i < NB_ITEM; i++) {
    addToCanvas(&test, 0, &canvas->_Game); }
  for (size_t i = 0; i < NB_ITEM; i++) {
    addToCanvas(&test2, 0, &canvas->_Game); }
  while (!WindowShouldClose()) {
    debug();
    TIME_START;
    rmFromRenderById(2, canvas);
    BeginDrawing();
    ClearBackground(BLACK);
    _pre_render(canvas);
    EndDrawing();
    LOG_MSG(TIME_STOP);
  }
  freeCanvas(&canvas);
  CloseWindow();
  return 0;
}