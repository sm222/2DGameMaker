#include "../inc/GMRender.h"

static t_ID _push_obj(t_RenderValue* const obj, t_addLayer* data) {
  size_t  i = data->_pos;
  t_Layers*    layer = data->_layers;
  if (layer->_ItemNumber[i] < layer->_LenRenderList[i]) {
    size_t j = 0;
    while (j < layer->_LenRenderList[i] && layer->_RenderList[i][j]) { j++; }
    if (j != layer->_LenRenderList[i]) {
      layer->_RenderList[i][j] = obj;
      layer->_ItemNumber[i]++;
      return obj->_Id;
    }
    else
      LOG_ERR("can't add obj, arr got full manualy");
  }
  else
    LOG_WAR("no space to add obj");
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
  if (id != 0)
    LOG_MSG("new obj");
  return id;
}