#include <stdio.h>

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "lal/lal_window.h"

int main()
{
	lal_print();

	// Open a connection to X server
	Display *display = XOpenDisplay(NULL);
	if(display == NULL)
	{
		printf("ERROR: Failed to open display.\n");
		return 1;
	}

	// Window size
	unsigned int width = 800;
	unsigned int height = 600;

	// Setup window config
	Window window = XCreateSimpleWindow(
			display,						// display
			DefaultRootWindow(display),		// parent
			0,								// x pos
			0,								// y pos
			width,							// width
			height,							// height
			0,								// border width
			0,								// border
			0);								// background

	// Report events associated with specified event mask
	XSelectInput(display, window, KeyPressMask);

	// Map window by client application
	XMapWindow(display, window);
	
	// Flush output buffer and wait for requests processed by X server
	XSync(display, 0);
	
	// Variable to read events
	XEvent event;
	
	// Variable to hold the delete window message
	unsigned long delete_msg = XInternAtom(display, "WM_DELETE_WINDOW", 0);
	XSetWMProtocols(display, window, &delete_msg, 1);
	long msg;
	
	// Variables to hold info about key pressed
	int len;
	char str[25] = {0};
	KeySym keysym = 0;

	printf("Starting window loop.\n");
	// Window loop
	int quit = 0;
	while(!quit)
	{
		XNextEvent(display, &event);

		switch(event.type)
		{
			case ClientMessage:
				msg = (long)delete_msg;
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
	
	// Close display
	XCloseDisplay(display);

	return 0;
}
