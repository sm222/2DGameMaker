#include "../inc/GMRender.h"

static t_ID _push_obj(t_RenderValue* const obj, t_addLayer* data) {
  size_t  i = data->_pos;
  if (data->_layers->_ItemNumber[i])
    return 0;
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
  else
    LOG_WAR("err add obj");
  return id;
}