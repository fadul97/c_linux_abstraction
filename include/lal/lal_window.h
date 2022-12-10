#ifndef LAL_WINDOW_H
#define LAL_WINDOW_H

#include "lal_defines.h"

typedef struct platform_handler
{
	void* window;
	b8 running;
} platform_handler;

b8 window_startup(
	platform_handler *platform_handler,
	const char* window_title,
	uint32 x,
	uint32 y,
	uint32 width,
	uint32 height);

void window_shutdown(platform_handler *platform_handler);

void process_events(platform_handler *platform_handler);

b8 is_platform_running(platform_handler *platform_handler);
void set_platform_running(platform_handler *platform_handler, b8 value);

#endif // LAL_WINDOW_H
