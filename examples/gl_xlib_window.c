#include "lal/lal_window.h"
#include "lal/lal_input.h"
#include <stdio.h>
#include <GL/glx.h>

int main()
{
	PlatformHandler plat;

    if(!create_gl_xlib_window(
        &plat,
        "OpenGL Window",
        0,
        0,
        800,
        600))
        return -1;

    run_gl_xlib_window(&plat);
    
	while(is_platform_running(&plat))
    {   
        process_gl_xlib_events(&plat);


        if(is_key_down(KEY_ESCAPE))
			set_platform_running(&plat, FALSE);
    }

    shutdown_gl_xlib_window(&plat);
	
	return 0;
}
