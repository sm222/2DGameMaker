#include "../inc/GMRender.h"

static int _Draw(const t_Layers* l) {
  (void)l;
  return 1;
}


int Render(t_Canvas* canvas) {
  if (!canvas) {
    LOG_ERR("Render: no Canvas");
    return 1;
  }
  const size_t total = _pre_render(canvas);
  if (DEV_LOG > none__) {
    char tmp[30];
    bzero(tmp, 30);
    snprintf(tmp, 30, "total layers %zu", total);
    LOG_MSG(tmp);
  }
  BeginDrawing();
  if (canvas->_Camera)
    BeginMode2D(*canvas->_Camera);
  _Draw(&canvas->_Game);
  if (canvas->_Camera)
    EndMode2D();
  _Draw(&canvas->_Ui);
  return 0;
}