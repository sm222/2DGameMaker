# include "C_tools/inc/C_tool.h"
# include "inc/GMRender.h"

int main() {
	TIME_START;
	t_RenderValue  test, test2;
	t_Canvas*      canvas = initCanvas();
	test._Id = 1;
	test2._Id = 2;
	test2.Depth = 1;
	test.Depth = 2;
	for (size_t i = 0; i < NB_ITEM; i++) {
		addToCanvas(&test, 0, &canvas->_Game);
	}
	for (size_t i = 0; i < NB_ITEM; i++) {
		addToCanvas(&test2, 0, &canvas->_Game);
	}
	_pre_render(canvas);
	resizeLayerAuto(&canvas->_Game, 0);
	resizeGame(canvas, 0);
	resizeGame(canvas, 0);
	freeCanvas(&canvas);
	LOG_MSG(TIME_STOP);
}