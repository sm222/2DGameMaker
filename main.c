# include "C_tools/inc/C_tool.h"
# include "inc/GMRender.h"

int main() {
	TIME_START;
	t_RenderValue  test;
	test._Id = 1;
	t_Canvas*      canvas = init_canvas();
	for (size_t i = 0; i < NB_ITEM; i++) {
		add_to_canvas(&test, 0, &canvas->_Game);
	}
	rm_layer(&canvas->_Game, 0);
	LOG_MSG(TIME_STOP);
	free_Canvas(&canvas);
}