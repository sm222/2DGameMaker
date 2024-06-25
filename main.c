# include "C_tools/inc/C_tool.h"
# include "inc/GMRender.h"

void debug(void) {
  static bool debug = false;
  if (debug) {
    char s[50];
    bzero(s, 50);
    snprintf(s, 50, "fps = %d", GetFPS());
    //DrawText(s, 0,0, 30, WHITE);
    DrawTextEx((Font){FONT_DEFAULT}, s, VEC2DEF, 30, 1, WHITE);
  }
  if (IsKeyPressed(KEY_BACKSPACE)) {
    if (debug) {
      debug = false;
      SetWindowOpacity(1);
    }
    else {
      debug = true;
      SetWindowOpacity(0.8);
    }
  }
}

int main() {
  t_Canvas*      canvas = InitCanvas();
  SetTraceLogLevel(LOG_NONE);
  InitWindow(700,700, "def game");
  SetTargetFPS(60);
  t_RenderValue  test, test2;
  test._Id = 1;
  test2._Id = 2;
  test2.Depth = 1;
  test.Depth = 2;
  for (size_t i = 0; i < NB_ITEM; i++) {
    AddToCanvas(&test, 0, &canvas->_Game); }
  for (size_t i = 0; i < NB_ITEM; i++) {
    AddToCanvas(&test2, 0, &canvas->_Game); }
    RmFromRenderById(2, canvas);
  while (!WindowShouldClose()) {
    BeginDrawing();
    TIME_START;
    debug();
    ClearBackground(BLACK);
    DrawTriangle(VEC2(100, 100), VEC2(100, 200), VEC2(200, 400), BLUE);
    DrawRectangleLinesEx((Rectangle){0,0, 100 , 100}, 1, BLUE);
    Render(canvas);
    EndDrawing();
    LOG_MSG(TIME_STOP);
  }
  FreeCanvas(&canvas);
  CloseWindow();
  return 0;
}