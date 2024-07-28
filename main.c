# include "C_tools/inc/C_tool.h"
# include "inc/GMRender.h"

#define len 200

int fpsTarget = 60;

/*
static Color degrad(int limit, int number) {
ColorAlphaBlend

}
ColorAlphaBlend()
*/


static void dfps(int ofset_x, int ofset_y ) {
  static int array[len];
  for (size_t i = 0; i < len - 1; i++) {
    Color c = GREEN;
    if (array[i] < 60) {
      int g = 0;
      for (int j = 0; j < array[i]; j++) {
        g += 4;
      }
      c.r = 255;
      c.g = g;
    }
    for (short j = 0; j < 50; j++){
      DrawPixel(ofset_x + i, (array[i] * -1) + ofset_y + j, c);
    }
    array[i] = array[i + 1];
  }
  array[len - 1] = ((GetFPS()));
  DrawFPS(ofset_x + 204, (array[len - 1] * -1) + ofset_y - 3);
}

void debug(void) {
  static int fpsV = 60;
  SetTargetFPS(fpsV);
  if (IsKeyDown(KEY_UP) && fpsV < 144)
    fpsV++;
  if (IsKeyDown(KEY_DOWN) && fpsV > 10)
    fpsV--;
}

void editCord(int *x, int *y) {
  if (IsKeyDown(KEY_A))
    (*x)--;
  if (IsKeyDown(KEY_D))
    (*x)++;
  if (IsKeyDown(KEY_W))
    (*y)--;
  if (IsKeyDown(KEY_S))
    (*y)++;
}

int main() {
  t_Canvas*      canvas = InitCanvas();
  SetTraceLogLevel(LOG_NONE);
  InitWindow(2000, 1000, "def game");
  SetTargetFPS(60);
  t_RenderValue  test;//, test2;
  int x = -2, y = 151;
  test._Id = 1;
  //test2._Id = 2;
  //test2.Depth = 1;
  Render2DTex *t = calloc(1, sizeof(Render2DTex));
  test.CRenderType.tex = t;
  test.CRenderType.tex->position.z = 2;
  AddToCanvas(&test, 5, &canvas->_Game);
  AddToCanvas(&test, 1, &canvas->_Game);
  AddToCanvas(&test, 0, &canvas->_Game);
  while (!WindowShouldClose()) {
    BeginDrawing();
    //TIME_START;
    debug();
    ClearBackground(BLACK);
    editCord(&x, &y);
    char R[40];
    sprintf(R, "x%d y%d", x, y);
    DrawText(R, 40, 40, 20, WHITE);
    dfps(x, y);
    Render(canvas);
    EndDrawing();
    //LOG_MSG(TIME_STOP);
  }
  FreeCanvas(&canvas);
  CloseWindow();
  return 0;
}
