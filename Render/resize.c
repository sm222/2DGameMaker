#include "../inc/GMRender.h"

short resize_auto(t_Layers* layer, size_t const y) {
  if (!layer) {
    LOG_WAR("resize_auto no layer pass");
    return 1;
  }
  if (y > layer->_SizeRenderList) {
    LOG_WAR("resize_auto out of range y");
    return 1;
  }
    size_t size = ((sizeof(**layer->_RenderList) * layer->_LenRenderList[y]));
  if (layer->_ItemNumber[y] > layer->_LenRenderList[y] / 2) {
    size = ((sizeof(**layer->_RenderList) * layer->_LenRenderList[y]) * 2);
    layer->_RenderList[y] = realloc(layer->_RenderList[y], size);
    LOG_MSG("resize_auto bigger");
  }
  else if (layer->_ItemNumber[y] < layer->_LenRenderList[y] / 4 && layer->_LenRenderList[y] > NB_ITEM) {
    size = ((sizeof(**layer->_RenderList) * layer->_LenRenderList[y]) / 2);
    layer->_RenderList[y] = realloc(layer->_RenderList[y], size);
    LOG_MSG("resize_auto smaler");
  }
  if (layer->_RenderList[y]) {
    layer->_LenRenderList[y] = (size / sizeof(**layer->_RenderList));
    return 0;
  }
  LOG_ERR("resize_auto calloc fail");
  layer->_LenRenderList[y] = 0;
  return 1;
}