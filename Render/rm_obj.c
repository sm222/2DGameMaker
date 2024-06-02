#include "../inc/GMRender.h"

static t_ID  _wipe_obj(t_Layers* layer, size_t const y, size_t const x) {
  t_ID const id = layer->_RenderList[y][x]->_Id;
  layer->_ItemNumber[y]--;
  layer->_RenderList[y][x] = NULL;
  return id;
}

static t_ID  _rm_id(t_ID const id, t_Layers* layer) {
  for (size_t i = 0; i < layer->_SizeRenderList; i++) {
    for (size_t j = 0; j < layer->_LenRenderList[i]; j++) {
      if (layer->_RenderList[i][j] && layer->_RenderList[i][j]->_Id == id) {
        LOG_MSG("remove by id sucsess");
        return _wipe_obj(layer, i, j);
      }
    }
  }
  return 0;
}

size_t  rm_layer(t_Layers* layer, size_t y) {
  if (!layer) {
    LOG_ERR("rm_layer no layer givent");
    return 0;
  }
  if (y > layer->_SizeRenderList) {
    LOG_WAR("rm_layer y out of bound");
    return 0;
  }
  size_t const tmp = layer->_ItemNumber[y];
  bzero(layer->_RenderList[y], sizeof(**layer->_RenderList) * tmp);
  layer->_ItemNumber[y] = 0;
  LOG_MSG("layer clean");
  return tmp;
}

t_ID       rm_obj_id(t_ID const id, t_Canvas* canvas) {
  if (!canvas || id == 0) {
    LOG_ERR("invalid arg rm_obj_id");
    return 0;
  }
  t_ID  _id = 0;
  _id += _rm_id(id, &canvas->_Game);
  _id += _rm_id(id, &canvas->_Ui);
  if (!_id)
    LOG_WAR("id not find");
  return _id;
}


t_ID rm_obj_cord(size_t const y, size_t const x, t_Layers* layer) {
  if (!layer) {
    LOG_ERR("rm_obj_cord no layer");
    return 0;
  }
  if (layer->_SizeRenderList < y) {
    LOG_WAR("rm_obj_cord out of bound y");
    return 0;
  }
  if (layer->_LenRenderList[y] < x) {
    LOG_WAR("rm_obj_cord out of bound x");
    return 0;
  }
  if (!layer->_RenderList[y][x]) {
    LOG_WAR("rm_obj_cord no item to tose cord");
    return 0;
  }
  LOG_MSG("rm_obj_cord sucsess");
  return _wipe_obj(layer, y, x);
}