#include "lal/lal_window.h"
#include "lal/lal_input.h"
#include <stdio.h>

int main()
{
	PlatformHandler plat;

	if(!create_simple_window(
			&plat,
			0,
			0,
			800,
			600))
		return -1;

	while(is_platform_running(&plat))
	{
		process_simple_window_events(&plat);		

		if(is_key_down(KEY_ESCAPE))
			set_platform_running(&plat, FALSE);
	}

	shutdown_simple_window(&plat);

	return 0;
}
