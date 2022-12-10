#include "lal/lal_window.h"
#include "lal/lal_input.h"
#include <stdio.h>

int main()
{
	platform_handler plat;

	if(!window_startup(
			&plat,
			"Testing Window",
			0,
			0,
			800,
			600))
		return -1;

	while(is_platform_running(&plat))
	{
		process_events(&plat);		

		if(is_key_down(KEY_ESCAPE))
		{
			printf("ESC Key pressed.\n");
			set_platform_running(&plat, FALSE);
		}
		
		printf("Loop.\n");
	}

	window_shutdown(&plat);

	return 0;
}
