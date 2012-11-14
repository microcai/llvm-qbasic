
#include <stdio.h>

int brt_print(int into, int num, ...)
{
	int ret = 0;
	printf("DEBUG: PRINT called , PRINT to %d with %d args\n", into, num);
	return ret;
}