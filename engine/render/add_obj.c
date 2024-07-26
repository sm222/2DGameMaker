#include "../../inc/GMRender.h"

static t_ID _push_obj(t_RenderValue* obj, const size_t y, t_Layers* layer) {
  if (layer->_LenRenderList[y] / 2 < layer->_ItemNumber[y])
    ResizeLayersAuto(layer, y);
  if (layer->_ItemNumber[y] < layer->_LenRenderList[y]) {
    size_t x = 0;
    while (x < layer->_LenRenderList[y] && layer->_RenderList[y][x]) { x++; }
    if (x != layer->_LenRenderList[y]) {
      layer->_RenderList[y][x] = obj;
      layer->_ItemNumber[y]++;
      return obj->_Id;
    }
    else
      LOG_ERR("_push_obj(): array is full (was tempered with)");
  }
  else
    LOG_WAR("_push_obj(): array is full");
  return 0;
}


t_ID AddToCanvas(t_RenderValue* obj, const size_t y, t_Layers* layer) {
  if (!obj) {
    LOG_ERR("add_to_canvas(): no object given");
    return 0;
  }
  t_ID id = 0;
  if (!layer) {
    LOG_ERR("add_to_canvas(): no layer given");
    return id;
  }
  if (y > layer->_SizeRenderList) {
    LOG_WAR("add_to_canvas(): y out of range");
    return id;
  }
  id = _push_obj(obj, y, layer);
  if (id != 0) {
    LOG_MSG("new obj");
    layer->_Edit[y] = true;
  }
  return id;
}