#include "../inc/GMRender.h"

void _free_layers(t_Layers* layers) {
  printf("%p\n", layers->_RenderList);
  printf("%zu\n", layers->_SizeRenderList);
  for (size_t i = 0; layers->_SizeRenderList; i++) {
    if (layers->_RenderList[i]) {
      free(layers->_RenderList[i]);
      layers->_RenderList[i] = NULL;
    }
  }
}

void free_Canvas(struct Canvas** canvas) {
  if (!canvas && !*canvas) {
    LOG_ERR("no canvas givent");
    return ;
  }
  struct Canvas* tmp = *canvas;
  _free_layers(&tmp->_Game);
  _free_layers(&tmp->_Ui);
  free((*canvas)->_Game._RenderList);
  free((*canvas)->_Ui._RenderList);
  free(*canvas);
  *canvas = NULL;
}
