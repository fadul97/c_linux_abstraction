#include "lal/lal_window.h"
#include "lal/lal_input.h"
#include <stdio.h>

int main()
{
	PlatformHandler plat;

    if(!create_xcb_window(
        &plat,
        "XCB Window",
        0,
        0,
        800,
        600))
        return -1;

    run_xcb_window(&plat);
    
	while(is_platform_running(&plat))
    {   
        process_xcb_events(&plat);

        if(is_key_down(KEY_ESCAPE))
			set_platform_running(&plat, FALSE);
    }

    shutdown_xcb_window(&plat);
	
	return 0;
}
