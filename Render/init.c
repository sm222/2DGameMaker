#include "../inc/GMRender.h"


t_ID add_to_anvas(struct RenderValue* obj, size_t layer, t_Depth depth) {
  if (!obj)
    return 0;
  
}

static int setup_RenderValue(struct Canvas* data) {
  data->_Game = calloc(DEF_LAYER + 1, sizeof(*data->_Game));
  if (!data->_Game)
    return 1;
  data->_Ui = calloc(DEF_UI + 1, sizeof(*data->_Ui));
  if (!data->_Ui) {
    free(data->_Game);
    return 2;
  }
  data->_UiSize = DEF_UI;
  data->_GameSize = DEF_LAYER;
  return 0;
}

struct Canvas*  init_canvas(void) {
  struct Canvas* tmp = NULL;
  tmp = calloc(1, sizeof(*tmp));
  if (!tmp) {
    perror("malloc init_canvas");
    return (NULL);
  }
  if (setup_RenderValue(tmp)) {
    free(tmp);
    tmp = NULL;
  }
  return tmp;
}
