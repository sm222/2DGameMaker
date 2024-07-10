
#ifndef GMRENDER_H
# define GMRENDER_H

# include "CDefine.h"
# include "../C_tools/inc/C_tool.h"
# include <pthread.h>

typedef struct _s_move_obj {
  t_RenderValue**  _list;
  pthread_mutex_t  _key;
  size_t           _len;
  char             _time[TMP_BUFF_SIZE];
} _t_move_obj;

#define  sort_ft(name)   void(*name)(_t_move_obj*)

int                Render(t_Canvas* canvas);
//                 |
struct Canvas*     InitCanvas(void);
void               FreeCanvas(struct Canvas** canvas);
t_ID               AddToCanvas(t_RenderValue* obj, const size_t y, t_Layers* layer);
//                 |
size_t             EmptyLayer(t_Layers* layer, const size_t y);
unsigned int       RmFromRenderById(const t_ID id, t_Canvas* canvas);
t_ID               RmFromRenderByCord(const size_t y, const size_t x, t_Layers* layer);
//                 |
short              ResizeLayerAuto(t_Layers* layer, const size_t y);
short              ResizeGame(t_Canvas* canvas, short dir);
short              resizeUi(t_Canvas* canvas, short dir);
//                 |
void              _free_layers(t_Layers* layers);
bool              _add_list(t_RenderValue*** _RenderList, const size_t i);
//                 |
size_t            _pre_render(struct Canvas* canvas);
//                 |
void              _bubble(_t_move_obj* data);
//                 |
void*              SetRenderAlgo(sort_ft(ft));
#endif // GMRENDER_H
