
#ifndef GMRENDER_H
# define GMRENDER_H

# include "CDefine.h"
# include "../C_tools/inc/C_tool.h"
# include <pthread.h>

typedef struct _s_move_obj {
    t_RenderValue**  _list;
    pthread_mutex_t  _key;
    size_t           _len;
    char             _time[BUFSIZ];
} _t_move_obj;

#define  sort_ft(name)   void(*name)(_t_move_obj*)

void test(void);

struct Canvas*     initCanvas(void);
void               freeCanvas(struct Canvas** canvas);
t_ID               addToCanvas(t_RenderValue* const obj, size_t const y, t_Layers* layer);
//                 |
size_t             emptyLayer(t_Layers* layer, size_t const y);
t_ID               rmFromRenderById(t_ID const id, t_Canvas* canvas);
t_ID               rmFromRenderByCord(size_t const y, size_t const x, t_Layers* layer);
//                 |
short              resizeLayerAuto(t_Layers* layer, size_t const y);
short              resizeGame(t_Canvas* canvas, short dir);
short              resizeUi(t_Canvas* canvas, short dir);
//                 |
void              _free_layers(t_Layers* layers);
bool              _add_list(t_RenderValue*** _RenderList, size_t const i);
//                 |
int               _pre_render(struct Canvas* canvas);
//                 |
void              _bubble(_t_move_obj* data);
//                 |
void*              set_render(void* ft);
#endif // GMRENDER_H
