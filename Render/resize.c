#include "../inc/GMRender.h"

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
    perror("_resize_t_Layers");
    LOG_ERR("#\\\\\\\\\\\\\\#");
    exit(1);
  }
  LOG_MSG("resize game");
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
    LOG_WAR("ResizeUi no canvas");
    return 1;
  }
  return _resize_t_Layers(&canvas->_Ui, edit_size(dir));
}

short ResizeGame(t_Canvas* canvas, short dir) {
  if (!canvas) {
    LOG_WAR("ResizeGame no canvas");
    return 1;
  }
  return _resize_t_Layers(&canvas->_Game, edit_size(dir));
}

short ResizeLayerAuto(t_Layers* layer, size_t const y) {
  if (!layer) {
    LOG_WAR("ResizeLayerAuto no layer pass");
    return 1;
  }
  if (y > layer->_SizeRenderList) {
    LOG_WAR("ResizeLayerAuto out of range y");
    return 1;
  }
    size_t size = ((sizeof(**layer->_RenderList) * layer->_LenRenderList[y]));
  if (layer->_ItemNumber[y] > layer->_LenRenderList[y] / 2) {
    size = ((sizeof(**layer->_RenderList) * layer->_LenRenderList[y]) * 2);
    layer->_RenderList[y] = realloc(layer->_RenderList[y], size);
    bzero(layer->_RenderList[y] +  layer->_LenRenderList[y],  size / 2);
    LOG_MSG("ResizeLayerAuto bigger");
  }
  else if (layer->_ItemNumber[y] < layer->_LenRenderList[y] / 4 && layer->_LenRenderList[y] > NB_ITEM) {
    size = ((sizeof(**layer->_RenderList) * layer->_LenRenderList[y]) / 2);
    layer->_RenderList[y] = realloc(layer->_RenderList[y], size);
    LOG_MSG("ResizeLayerAuto smaler");
  }
  if (layer->_RenderList[y]) {
    layer->_LenRenderList[y] = (size / sizeof(**layer->_RenderList));
    return 0;
  }
  LOG_ERR("ResizeLayerAuto calloc fail");
  layer->_LenRenderList[y] = 0;
  return 1;
}