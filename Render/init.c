#include "../inc/GMRender.h"

void* SetRenderAlgo(sort_ft(ft)) {
  static sort_ft(tmp) = &_bubble;
  if (ft)
    tmp = ft;
  return tmp;
}

bool _add_list(t_RenderValue*** _RenderList, const size_t i) {
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
  data->_Game._SizeRenderList = DEF_LAYER;
  data->_Ui._SizeRenderList = DEF_UI;
  bzero(data->_Game._Edit, sizeof(*data->_Game._Edit) * DEF_LAYER);
  bzero(data->_Ui._Edit, sizeof(*data->_Ui._Edit) * DEF_UI);
  return 0;
}

struct Canvas*  InitCanvas(void) {
  struct Canvas* tmp = NULL;
  tmp = calloc(1, sizeof(*tmp));
  if (!tmp) {
    perror("malloc InitCanvas");
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
