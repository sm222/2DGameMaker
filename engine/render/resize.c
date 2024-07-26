#include "../../inc/GMRender.h"

static short _resize_t_Layers(t_Layers* layer, short dir) {
  if (layer->_SizeRenderList > 1 && dir < 0) {
    free(layer->_RenderList[layer->_SizeRenderList -1]);
    layer->_RenderList = realloc(layer->_RenderList, sizeof(*layer->_RenderList) * (layer->_SizeRenderList - dir));
    layer->_SizeRenderList += dir;
  }
  else if (dir > 0) {
    layer->_RenderList = realloc(layer->_RenderList, sizeof(*layer->_RenderList) * (layer->_SizeRenderList + dir));
    if (layer->_RenderList) {
      layer->_RenderList[layer->_SizeRenderList] = NULL;
      _add_list(layer->_RenderList, layer->_SizeRenderList);
      layer->_SizeRenderList += dir;
    }
  }
  else
    return 0;
  if (!layer->_RenderList) {
    LOG_ERR("#///////#");
    perror("_resize_t_Layers()");
    LOG_ERR("#\\\\\\\\\\\\\\#");
    exit(1);
  }
  LOG_MSG("resized layers");
  return 0;
}

static short edit_size(short nb) {
  if (nb) {
    while (nb > 1)
      nb--;
  }
  if (nb < -1) {
    while (nb < -1)
      nb++;
  }
  return nb;
}

short resizeUi(t_Canvas* canvas, short dir) {
  if (!canvas) {
    LOG_WAR("ResizeUi(): no canvas given");
    return 1;
  }
  return _resize_t_Layers(&canvas->_Ui, edit_size(dir));
}

short ResizeGame(t_Canvas* canvas, short dir) {
  if (!canvas) {
    LOG_WAR("ResizeGame(): no canvas given");
    return 1;
  }
  return _resize_t_Layers(&canvas->_Game, edit_size(dir));
}

short ResizeLayersAuto(t_Layers* layer, const size_t y) {
  if (!layer) {
    LOG_WAR("ResizeLayersAuto(): no layer given");
    return 1;
  }
  if (y > layer->_SizeRenderList) {
    LOG_WAR("ResizeLayersAuto(): y out of range");
    return 1;
  }
    size_t size = ((sizeof(**layer->_RenderList) * layer->_LenRenderList[y]));
  if (layer->_ItemNumber[y] > layer->_LenRenderList[y] / 2) {
    size = ((sizeof(**layer->_RenderList) * layer->_LenRenderList[y]) * 2);
    layer->_RenderList[y] = realloc(layer->_RenderList[y], size);
    bzero(layer->_RenderList[y] +  layer->_LenRenderList[y],  size / 2);
    LOG_MSG("ResizeLayersAuto(): made layers bigger");
  }
  else if (layer->_ItemNumber[y] < layer->_LenRenderList[y] / 4 && layer->_LenRenderList[y] > NB_ITEM) {
    size = ((sizeof(**layer->_RenderList) * layer->_LenRenderList[y]) / 2);
    layer->_RenderList[y] = realloc(layer->_RenderList[y], size);
    LOG_MSG("ResizeLayersAuto(): made layers smaller");
  }
  if (layer->_RenderList[y]) {
    layer->_LenRenderList[y] = (size / sizeof(**layer->_RenderList));
    return 0;
  }
  LOG_ERR("ResizeLayersAuto() calloc failed");
  layer->_LenRenderList[y] = 0;
  return 1;
}