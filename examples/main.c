#include "lal/lal_window.h"

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

	if(!window_run(&plat))
		return -1;

	window_shutdown(&plat);

	return 0;
}
