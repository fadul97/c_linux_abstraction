#include "lal_defines.h"
#include "lal/lal_window.h"

#if LPLATFORM_LINUX

#include <stdio.h>

void lal_print()
{
	printf("Printing from lal_window.h\n");
}

#endif // LPLATFORM_LINUX
