# include "C_tools/inc/C_tool.h"
# include "inc/GMRender.h"

int main() {
	TIME_START;
	t_RenderValue  test;
	t_Canvas*      canvas = init_canvas();
	test._Id = 1;
	for (size_t i = 0; i < NB_ITEM * 2; i++) {
		add_to_canvas(&test, 0, &canvas->_Game);
	}
	rm_layer(&canvas->_Game, 0);
	printf("%zu\n", canvas->_Game._LenRenderList[0]);
	resize_auto(&canvas->_Game, 0);
	printf("%zu\n", canvas->_Game._LenRenderList[0]);
	resize_auto(&canvas->_Game, 0);
	printf("%zu\n", canvas->_Game._LenRenderList[0]);
	resize_auto(&canvas->_Game, 0);
	printf("%zu\n", canvas->_Game._LenRenderList[0]);
	resize_auto(&canvas->_Game, 0);
	printf("%zu\n", canvas->_Game._LenRenderList[0]);
	LOG_MSG(TIME_STOP);
	free_Canvas(&canvas);
}