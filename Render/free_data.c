#include "../inc/GMRender.h"

void _free_layers(t_Layers* layers) {
  for (size_t i = 0; i < layers->_SizeRenderList; i++) {
    free(layers->_RenderList[i]);
    layers->_RenderList[i] = NULL;
  }
}

void freeCanvas(struct Canvas** canvas) {
  if (!canvas && !*canvas) {
    LOG_ERR("no canvas givent");
    return ;
  }
  struct Canvas* tmp = *canvas;
  _free_layers(&tmp->_Game);
  _free_layers(&tmp->_Ui);
  free(tmp->_Game._RenderList);
  free(tmp->_Ui._RenderList);
  free(*canvas);
  *canvas = NULL;
}
