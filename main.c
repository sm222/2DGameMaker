# include "C_tools/inc/C_tool.h"
# include "inc/GMRender.h"

int main() {
	//test();
	TIME_START;
	t_Canvas *canvas = init_canvas();
	LOG_MSG(TIME_STOP);
	free_Canvas(&canvas);
}