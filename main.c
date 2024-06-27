# include "C_tools/inc/C_tool.h"
# include "inc/GMRender.h"

#define len 200

int fpsTarget = 60;

static void dfps(void) {
  static int f[len];
  static int j = len;
  Image img;
  img = GenImageColor(200, 300, BLACK);

  if (j == 0)
    j = len;
  f[--j] = GetFPS();
  for (size_t i = len; i > 0; --i) {
    DrawPixel(i, ((f[i] * -1)) + 300, RED);
    ImageDrawPixel(&img, i, f[i], RED);
  }
  Texture2D t = LoadTextureFromImage(img);
  DrawTexture(t, 300, 300, WHITE);
}

void debug(void) {
  static bool debug = false;
  if (debug) {
    char s[50];
    bzero(s, 50);
    snprintf(s, 50, "fps = %d", GetFPS());
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
    //TIME_START;
    debug();
    ClearBackground(BLACK);
    dfps();
    Render(canvas);
    EndDrawing();
    //LOG_MSG(TIME_STOP);
  }
  FreeCanvas(&canvas);
  CloseWindow();
  return 0;
}