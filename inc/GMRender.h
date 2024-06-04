
#ifndef GMRENDER_H
# define GMRENDER_H

# include "CDefine.h"
# include "../C_tools/inc/C_tool.h"

void test(void);

struct Canvas*     init_canvas(void);
void               free_Canvas(struct Canvas** canvas);
t_ID               add_to_canvas(t_RenderValue* const obj, size_t y, t_Layers* layer);
//                 |
size_t             rm_layer(t_Layers* layer, size_t y);
t_ID               rm_obj_id(t_ID const id, t_Canvas* canvas);
t_ID               rm_obj_cord(size_t const y, size_t const x, t_Layers* layer);
//                 |
short              resize_auto(t_Layers* layer, size_t const y);
short              resize_game(t_Canvas* canvas, short dir);
//                 |
void              _free_layers(t_Layers* layers);
bool              _add_list(t_RenderValue*** _RenderList, size_t i);

#endif // GMRENDER_H
