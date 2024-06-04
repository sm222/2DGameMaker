#include "../inc/GMRender.h"

void test(void) {
	TIME_START;
	for (size_t i = 0; i < 100; i++) {
		TIME_RESTART;
		usleep(i * i);
		LOG_MSG(TIME_STOP);
	}
	return ;
}
