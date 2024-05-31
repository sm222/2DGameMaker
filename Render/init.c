#include "../inc/GMRender.h"

static t_ID _push_obj(t_RenderValue* const obj, t_addLayer* data) {
  size_t  i = data->_pos;
  if (data->_layers->_ItemNumber[i])
    return 1;
  (void)obj;

  //while () {
  //  
  //}
  return 0;
}


t_ID add_to_canvas(t_RenderValue* const obj, t_addLayer data) {
  if (!obj) {
    LOG_ERR("no obj give: add_to_anvas");
    return 0;
  }
  t_ID id = 0;
  if (!data._layers) {
    LOG_ERR("no layer give");
    return id;
  }
  if (data._pos > data._layers->_SizeRenderList) {
    LOG_WAR("out of range");
    return id;
  }
  id = _push_obj(obj, &data);
  return id;
}

static int _add_list(t_RenderValue*** _RenderList, size_t i) {
  if (!_RenderList[i]) {
    _RenderList[i] = calloc(NB_ITEM + 1, sizeof(*_RenderList));
    if (!_RenderList[i])
      return 1;
  }
  return 0;
}

void _free_layers(t_Layers* layers) {
  for (size_t i = 0; layers->_RenderList[i]; i++) {
    if (layers->_RenderList[i]) {
      free(layers->_RenderList[i]);
      layers->_RenderList[i] = NULL;
    }
  }
}

static int _setup_RenderValue(struct Canvas* data) {
  data->_Game._RenderList = calloc(DEF_LAYER + 1, sizeof(**data->_Game._RenderList));
  if (!data->_Game._RenderList)
    return 1;
  data->_Ui._RenderList = calloc(DEF_UI + 1, sizeof(**data->_Ui._RenderList));
  if (!data->_Ui._RenderList) {
    free(data->_Game._RenderList);
    return 2;
  }
  for (size_t i = 0; i < DEF_LAYER; i++) {
    if(_add_list(data->_Game._RenderList, i)) {
      _free_layers(&data->_Game);
      return 1;
    }
  }
  for (size_t i = 0; i < DEF_UI; i++) {
    if(_add_list(data->_Ui._RenderList, i)) {
      _free_layers(&data->_Ui);
      return 2;
    }
  }
  data->_Ui._SizeRenderList = DEF_UI;
  data->_Game._SizeRenderList = DEF_LAYER;
  return 0;
}

void free_Canvas(struct Canvas** canvas) {
  if (!canvas) {
    LOG_ERR("no canvas givent");
    return ;
  }
  _free_layers(&(*canvas)->_Game);
  _free_layers(&(*canvas)->_Ui);
  free((*canvas)->_Game._RenderList);
  free((*canvas)->_Ui._RenderList);
  free(*canvas);
  *canvas = NULL;
}

struct Canvas*  init_canvas(void) {
  struct Canvas* tmp = NULL;
  tmp = calloc(1, sizeof(*tmp));
  if (!tmp) {
    perror("malloc init_canvas");
    return (NULL);
  }
  if (_setup_RenderValue(tmp)) {
    free(tmp);
    tmp = NULL;
  }
  LOG_MSG("new canvas");
  return tmp;
}
