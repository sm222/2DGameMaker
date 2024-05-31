#include "../inc/GMRender.h"

void _free_layers(t_Layers* layers) {
  for (size_t i = 0; layers->_RenderList[i]; i++) {
    if (layers->_RenderList[i]) {
      free(layers->_RenderList[i]);
      layers->_RenderList[i] = NULL;
    }
  }
}

void free_Canvas(struct Canvas** canvas) {
  if (!canvas) {
    LOG_ERR("no canvas givent");
    return ;
  }
  _free_layers(&(*canvas)->_Game);
  _free_layers(&(*canvas)->_Ui);
  free((*canvas)->_Game._RenderList);
  free((*canvas)->_Ui._RenderList);
  free(*canvas);
  *canvas = NULL;
}
