#include "../inc/GMRender.h"

static void _opti_space(_t_move_obj* data) {
  size_t  i = 0;
  while (i < data->_len) {
    if (i + 1 < data->_len && !data->_list[i] && data->_list[i + 1]) {
      data->_list[i] = data->_list[i + 1];
      data->_list[i + 1] = NULL;
      i = -1;
    }
    i++;
  }
}

void  _bubble(_t_move_obj* data) {
  t_RenderValue* tmp;
  for (size_t i = 0; i < data->_len && data->_list[i]; i++) {
    if (data->_list[i] && data->_list[i + 1]) {
      if (data->_list[i]->Depth > data->_list[i + 1]->Depth) {
        tmp = data->_list[i + 1];
        data->_list[i + 1] = data->_list[i];
        data->_list[i] = tmp;
        i = -1;
      }
    }
  }
}

static void* _sort(void* data) {
  _t_move_obj* c = (_t_move_obj*)data;
  TIME_START;
  _opti_space(c);
  void  (*ft)(_t_move_obj*);
  ft = SetRenderAlgo(NULL);
  ft(data);
  strcpy(c->_time, TIME_STOP);
  return data;
}

static size_t _move_obj(struct Layers* layer) {
  size_t nb = layer->_SizeRenderList;

  for (size_t i = 0; i < layer->_SizeRenderList; i++) {
    if (!layer->_Edit[i])
      nb--;
  }
  if (!nb)
    return 0;
  size_t      j = 0;
  pthread_t   threads[nb];
  _t_move_obj data[nb];
  for (size_t i = 0; i < nb; i++) {
    bzero(data[i]._time, TMP_BUFF_SIZE);
    while (i + j <  layer->_SizeRenderList && !layer->_Edit[i + j]) {
      j++;
    }
    data[i]._list = layer->_RenderList[i + j];
    data[i]._len = layer->_LenRenderList[i + j];
    printf("%zu > %zu \n", i , i + j);
    //pthread_create(thread[i], NULL, &task, ph[i]);
    /*const int r =*/
    pthread_create(&threads[i], NULL, &_sort, &data[i]);
    layer->_Edit[i + j] = false;
    //err[i] = (r != 0 ? true : false);
    j = 0;
  }
  for (size_t i = 0; i < nb; i++) {
    pthread_join(threads[i], NULL);
  }
  return nb;
}

size_t _pre_render(struct Canvas* canvas) {
  size_t items = 0;
  items += _move_obj(&canvas->_Game);
  items += _move_obj(&canvas->_Ui);
  return items;
}