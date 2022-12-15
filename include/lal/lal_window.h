#ifndef LAL_WINDOW_H
#define LAL_WINDOW_H

#include "lal_defines.h"

typedef struct PlatformHandler
{
	void* window;
	b8 running;
} PlatformHandler;

b8 create_simple_window(
	PlatformHandler *platform_handler,
	uint32 x,
	uint32 y,
	uint32 width,
	uint32 height);

b8 create_gl_xlib_window(
	PlatformHandler *platform_handler,
	const char* window_title,
	uint32 x,
	uint32 y,
	uint32 width,
	uint32 height);

void run_gl_xlib_window(PlatformHandler *platform_handler);

void shutdown_simple_window(PlatformHandler *platform_handler);
void shutdown_gl_xlib_window(PlatformHandler *platform_handler);

void process_simple_window_events(PlatformHandler *platform_handler);
void process_gl_xlib_events(PlatformHandler *platform_handler);

b8 is_platform_running(PlatformHandler *platform_handler);
void set_platform_running(PlatformHandler *platform_handler, b8 value);

#endif // LAL_WINDOW_H
