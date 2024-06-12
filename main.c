# include "C_tools/inc/C_tool.h"
# include "inc/GMRender.h"

int main() {
	TIME_START;
	t_RenderValue  test, test2;
	t_Canvas*      canvas = init_canvas();
	test._Id = 1;
	test2._Id = 2;
	test2.Depth = 1;
	test.Depth = 2;
	for (size_t i = 0; i < NB_ITEM / 2; i++) {
		add_to_canvas(&test, 0, &canvas->_Game);
	}
	for (size_t i = 0; i < NB_ITEM / 2; i++) {
		add_to_canvas(&test2, 0, &canvas->_Game);
	}
	_pre_render(canvas);
	resize_auto(&canvas->_Game, 0);
	resize_game(canvas, 0);
	resize_game(canvas, 0);
	LOG_MSG(TIME_STOP);
	free_Canvas(&canvas);
}