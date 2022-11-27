#ifndef LAL_WINDOW_H
#define LAL_WINDOW_H

#include "lal_defines.h"

typedef struct platform_handler
{
	void* window;
} platform_handler;

b8 window_startup(
	platform_handler *platform_handler,
	const char* window_title,
	uint32 x,
	uint32 y,
	uint32 width,
	uint32 height);

void window_shutdown(platform_handler *platform_handler);

b8 window_run(platform_handler *platform_handler);

#endif // LAL_WINDOW_H
