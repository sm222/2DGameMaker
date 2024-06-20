#include "../inc/GMRender.h"

static t_ID  _wipe_obj(t_Layers* layer, size_t const y, size_t const x) {
  t_ID const id = layer->_RenderList[y][x]->_Id;
  layer->_ItemNumber[y]--;
  layer->_RenderList[y][x] = NULL;
  return id;
}

static unsigned int  _rm_id(t_ID const id, t_Layers* layer) {
  unsigned int  nb = 0;
  char    buff[BUFSIZ];

  for (size_t i = 0; i < layer->_SizeRenderList; i++) {
    for (size_t j = 0; j < layer->_LenRenderList[i]; j++) {
      if (layer->_RenderList[i][j] && layer->_RenderList[i][j]->_Id == id) {
        if (_wipe_obj(layer, i, j) == id)
          nb++;
      }
    }
  }
  bzero(buff, BUFSIZ);
  snprintf(buff, BUFSIZ, "obj remove %u", nb);
  LOG_MSG(buff);
  return nb;
}

size_t  EmptyLayer(t_Layers* layer, size_t const y) {
  if (!layer) {
    LOG_ERR("EmptyLayer no layer givent");
    return 0;
  }
  if (y > layer->_SizeRenderList) {
    LOG_WAR("EmptyLayer y out of bound");
    return 0;
  }
  size_t const tmp = layer->_ItemNumber[y];
  bzero(layer->_RenderList[y], sizeof(**layer->_RenderList) * tmp);
  layer->_ItemNumber[y] = 0;
  LOG_MSG("layer clean");
  return tmp;
}

unsigned int  RmFromRenderById(t_ID const id, t_Canvas* canvas) {
  if (!canvas || id == 0) {
    LOG_ERR("invalid arg RmFromRenderById");
    return 0;
  }
  unsigned int  _id = 0;
  _id += _rm_id(id, &canvas->_Game);
  _id += _rm_id(id, &canvas->_Ui);
  if (!_id)
    LOG_WAR("id not find");
  return _id;
}


t_ID RmFromRenderByCord(size_t const y, size_t const x, t_Layers* layer) {
  if (!layer) {
    LOG_ERR("RmFromRenderByCord no layer");
    return 0;
  }
  if (layer->_SizeRenderList < y) {
    LOG_WAR("RmFromRenderByCord out of bound y");
    return 0;
  }
  if (layer->_LenRenderList[y] < x) {
    LOG_WAR("RmFromRenderByCord out of bound x");
    return 0;
  }
  if (!layer->_RenderList[y][x]) {
    LOG_WAR("RmFromRenderByCord no item to tose cord");
    return 0;
  }
  LOG_MSG("RmFromRenderByCord sucsess");
  return _wipe_obj(layer, y, x);
}