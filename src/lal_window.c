#include "lal_defines.h"
#include "lal/lal_window.h"

#if LPLATFORM_LINUX

#include <stdio.h>
#include <stdlib.h>

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

typedef struct WindowX11
{
	Display *display;
	ulong32 id;
	Screen screen;
	ulong32 delete_msg;
} WindowX11;


b8 window_startup(
		platform_handler *platform_handler,
		const char* window_title,
		uint32 x,
		uint32 y,
		uint32 width,
		uint32 height)
{
	// Create WindowX11
	platform_handler->window = malloc(sizeof(WindowX11));
	WindowX11 *window = (WindowX11 *)platform_handler->window;
	
	// Open a connection to X server
	window->display = XOpenDisplay(NULL);
	if(window->display == NULL)
	{
		printf("ERROR: Failed to open display.\n");
		return 1;
	}

	// Setup window config
	window->id = XCreateSimpleWindow(
			window->display,					// display
			DefaultRootWindow(window->display),	// parent
			x,									// x pos
			y,									// y pos
			width,								// width
			height,								// height
			0,									// border width
			0,									// border
			0);									// background

	// Report events associated with specified event mask
	XSelectInput(window->display, window->id, KeyPressMask);

	// Map window by client application
	XMapWindow(window->display, window->id);
	
	// Flush output buffer and wait for requests processed by X server
	XSync(window->display, 0);
	
	// Variable to hold the delete window message
	window->delete_msg = XInternAtom(window->display, "WM_DELETE_WINDOW", 0);
	XSetWMProtocols(window->display, window->id, &window->delete_msg, 1);

	return TRUE;
}

void window_shutdown(platform_handler *platform_handler)
{
	WindowX11 *window = (WindowX11 *)platform_handler->window;
	XCloseDisplay(window->display);
	
	if(platform_handler->window != NULL)
	{
		free(window);
		printf("Window pointer deleted.\n");
	}
}

b8 window_run(platform_handler *platform_handler)
{
	WindowX11 *window = (WindowX11 *)platform_handler->window;

	// Variable to read events
	XEvent event;

	// Variables to hold info about key pressed
	int len;
	char str[25] = {0};
	KeySym keysym = 0;
	slong32 msg;

	printf("Starting window loop.\n");
	// Window loop
	int quit = 0;
	while(!quit)
	{
		XNextEvent(window->display, &event);

		switch(event.type)
		{
			case ClientMessage:
				msg = (long)window->delete_msg;
				if(event.xclient.data.l[0] == msg)
					quit = 1;
				break;
			case KeyPress:
				len = XLookupString(&event.xkey, str, 25, &keysym, NULL);
				if(len > 0)
				{
					printf("Key pressed: %s - %d - %ld\n", str, len, keysym);
					if(keysym == XK_Escape)
						quit = 1;
				}
				break;
			default:
				break;
		}
	}

	return TRUE;
}

#endif // LPLATFORM_LINUX
