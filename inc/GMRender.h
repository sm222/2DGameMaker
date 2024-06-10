
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


void test(void);

struct Canvas*     init_canvas(void);
void               free_Canvas(struct Canvas** canvas);
t_ID               add_to_canvas(t_RenderValue* const obj, size_t const y, t_Layers* layer);
//                 |
size_t             rm_layer(t_Layers* layer, size_t const y);
t_ID               rm_obj_id(t_ID const id, t_Canvas* canvas);
t_ID               rm_obj_cord(size_t const y, size_t const x, t_Layers* layer);
//                 |
short              resize_auto(t_Layers* layer, size_t const y);
short              resize_game(t_Canvas* canvas, short dir);
short              resize_ui(t_Canvas* canvas, short dir);
//                 |
void              _free_layers(t_Layers* layers);
bool              _add_list(t_RenderValue*** _RenderList, size_t const i);
//                 |
int               _pre_render(struct Canvas* canvas);

#endif // GMRENDER_H
