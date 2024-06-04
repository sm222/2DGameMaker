#include "../inc/GMRender.h"

static short _resize_t_Layers(t_Layers* layer, short dir) {
  printf("- > %zu\n", layer->_SizeRenderList);
  if (layer->_SizeRenderList > 1 && dir < 0) {
    layer->_RenderList = realloc(layer->_RenderList, sizeof(*layer->_RenderList) * (layer->_SizeRenderList  - dir));
    layer->_SizeRenderList += dir;
  }
  else if (dir > 0) {
    layer->_RenderList = realloc(layer->_RenderList, sizeof(*layer->_RenderList) * (layer->_SizeRenderList  + dir));
    layer->_SizeRenderList += dir;
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

short resize_game(t_Canvas* canvas, short dir) {
  if (!canvas || 1) {
    LOG_WAR("resize_game no canvas");
    return 1;
  }
  if (dir) {
    while (dir > 1)
      dir--;
  }
  if (dir < -1) {
    while (dir < -1)
      dir++;
  }
  return _resize_t_Layers(&canvas->_Game, dir);
}

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