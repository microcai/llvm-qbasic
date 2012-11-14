
#include <stdio.h>
#include <stdarg.h>
#include </home/cai/projects/basic/include/defines.h>

#include "defines.h"

int brt_print(int into, int num, ...)
{
	int i = 0;
	int ret = 0;
	printf("DEBUG: PRINT called , PRINT to %d with %d args\n", into, num);

	va_list va;

	va_start(va,num);

	for( ; i < num ; i++)
	{
		switch(va_arg(va,int))
		{
			case EXPR_TYPE_BOOL:
			case EXPR_TYPE_BYTE:	// for const char * used with CARRAY
			case EXPR_TYPE_SHORT:	// as short
			case EXPR_TYPE_INTGER:	// as Intger
				printf("%d\t",va_arg(va,int));
				break;
			case EXPR_TYPE_LONG:
				printf("%l",(long)(va_arg(va,long)));
				break;				
		}		
	}
	fflush(stdout);
	
	return ret;
}