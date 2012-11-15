
#include <stdio.h>
#include <stdarg.h>

void brt_print(int into, const char * fmt,...)
{
	int ret = 0;
	va_list va;
	va_start(va,fmt);
	//fprintf(stdout)
	ret = vprintf(fmt,va);
	///return ret;
}