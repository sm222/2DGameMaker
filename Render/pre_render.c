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
  ft = set_render(NULL);
  ft(data);
  strcpy(c->_time, TIME_STOP);
  return data;
}

static int _move_obj(struct Layers* layer) {
  const size_t nb = layer->_SizeRenderList;
  if (!nb)
    return 0;
  pthread_t    threads[nb];
  _t_move_obj  data[nb];
  //bool         err[nb];

  for (size_t i = 0; i < nb; i++) {
    bzero(data[i]._time, BUFSIZ);
    data[i]._list = layer->_RenderList[i];
    data[i]._len = layer->_LenRenderList[i];
    //pthread_create(thread[i], NULL, &task, ph[i]);
    /*const int r =*/pthread_create(&threads[i], NULL, &_sort, &data[i]);
    //err[i] = (r != 0 ? true : false);
  }
  for (size_t i = 0; i < nb; i++) {
    pthread_join(threads[i], NULL);
  }
  for (size_t i = 0; i < nb; i++) {
    printf("[%zu]>%s\n", i, data[i]._time);
  }
  return nb;
}

int _pre_render(struct Canvas* canvas) {
  _move_obj(&canvas->_Game);
  //_move_obj(&canvas->_Ui);
  return 0;
}