
#ifndef GMRENDER_H
# define GMRENDER_H

# include "CDefine.h"
# include "../C_tools/inc/C_tool.h"

void test(void);

struct Canvas*  init_canvas(void);
void free_Canvas(struct Canvas** canvas);


//
void _free_layers(t_Layers* layers);

#endif // GMRENDER_H
