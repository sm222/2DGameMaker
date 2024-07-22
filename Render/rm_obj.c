#include "../inc/GMRender.h"

static t_ID  _wipe_obj(t_Layers* layer, const size_t y, const size_t x) {
  const t_ID id = layer->_RenderList[y][x]->_Id;
  layer->_ItemNumber[y]--;
  layer->_RenderList[y][x] = NULL;
  return id;
}

static unsigned int  _rm_id(const t_ID id, t_Layers* layer) {
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
  snprintf(buff, BUFSIZ, "_rm_id(): object removed %u", nb);
  LOG_MSG(buff);
  return nb;
}

size_t  EmptyLayer(t_Layers* layer, const size_t y) {
  if (!layer) {
    LOG_ERR("EmptyLayer(): no layer given");
    return 0;
  }
  if (y > layer->_SizeRenderList) {
    LOG_WAR("EmptyLayer(): y out of bound");
    return 0;
  }
  const size_t tmp = layer->_ItemNumber[y];
  bzero(layer->_RenderList[y], sizeof(**layer->_RenderList) * tmp);
  layer->_ItemNumber[y] = 0;
  LOG_MSG("EmptyLayer(): layer cleaned");
  return tmp;
}

unsigned int  RmFromRenderById(const t_ID id, t_Canvas* canvas) {
  if (!canvas || id == 0) {
    LOG_ERR("EmptyLayer(): invalid input");
    return 0;
  }
  unsigned int  _id = 0;
  _id += _rm_id(id, &canvas->_Game);
  _id += _rm_id(id, &canvas->_Ui);
  if (!_id)
    LOG_WAR("EmptyLayer(): ID not found");
  return _id;
}


t_ID RmFromRenderByCord(const size_t y, const size_t x, t_Layers* layer) {
  if (!layer) {
    LOG_ERR("RmFromRenderByCord(): no layer given");
    return 0;
  }
  if (layer->_SizeRenderList < y) {
    LOG_WAR("RmFromRenderByCord(): y out of bound");
    return 0;
  }
  if (layer->_LenRenderList[y] < x) {
    LOG_WAR("RmFromRenderByCord(): x out of bound");
    return 0;
  }
  if (!layer->_RenderList[y][x]) {
    LOG_WAR("RmFromRenderByCord(): no item at those coords");
    return 0;
  }
  LOG_MSG("RmFromRenderByCord(): success");
  return _wipe_obj(layer, y, x);
}