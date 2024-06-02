# include "C_tools/inc/C_tool.h"
# include "inc/GMRender.h"

int main() {
	TIME_START;
	t_RenderValue  test;
	t_Canvas*      canvas = init_canvas();
	t_addLayer     layer;
	test._Id = 1;
	layer._Depth = 0;
	layer._layers = &canvas->_Game;
	for (size_t i = 0; i < 3; i++) {
		layer._pos = 0;
		add_to_canvas(&test, layer);
	}
	LOG_MSG(TIME_STOP);
	free_Canvas(&canvas);
}