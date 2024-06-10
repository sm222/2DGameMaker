#include "../inc/GMRender.h"

bool _add_list(t_RenderValue*** _RenderList, size_t const i) {
  if (!_RenderList[i]) {
    _RenderList[i] = calloc(NB_ITEM, sizeof(**_RenderList));
    if (!_RenderList[i]) {
      return 1;
    }
  }
  return 0;
}

static int _setup_RenderValue(struct Canvas* data) {
  data->_Game._RenderList = calloc(DEF_LAYER, sizeof(*data->_Game._RenderList));
  if (!data->_Game._RenderList)
    return 1;
  data->_Ui._RenderList = calloc(DEF_UI, sizeof(*data->_Ui._RenderList));
  if (!data->_Ui._RenderList) {
    free(data->_Game._RenderList);
    return 2;
  }
  for (size_t i = 0; i < DEF_LAYER; i++) {
    data->_Game._LenRenderList[i] = NB_ITEM;
    if (_add_list(data->_Game._RenderList, i)) {
      _free_layers(&data->_Game);
      return 1;
    }
  }
  for (size_t i = 0; i < DEF_UI; i++) {
    data->_Ui._LenRenderList[i] = NB_ITEM;
    if(_add_list(data->_Ui._RenderList, i)) {
      _free_layers(&data->_Ui);
      return 2;
    }
  }
  data->_Ui._SizeRenderList = DEF_UI;
  data->_Game._SizeRenderList = DEF_LAYER;
  return 0;
}

struct Canvas*  init_canvas(void) {
  struct Canvas* tmp = NULL;
  tmp = calloc(1, sizeof(*tmp));
  if (!tmp) {
    perror("malloc init_canvas");
    return (NULL);
  }
  if (_setup_RenderValue(tmp)) {
    perror("malloc _setup_RenderValue");
    free(tmp);
    tmp = NULL;
    return NULL;
  }
  LOG_MSG("new canvas");
  return tmp;
}
