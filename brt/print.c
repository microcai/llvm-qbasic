
#include <stdio.h>
#include <stdarg.h>

#include "defines.h"

int brt_print(int into, int num, ...)
{
	int i = 0;
	int ret = 0;

	va_list va;

	va_start(va,num);

	for(i=0 ; i < num ; i++)
	{
		int type = va_arg(va,int);
		switch(type)
		{
			case EXPR_TYPE_BOOL:
			case EXPR_TYPE_BYTE:	// for const char * used with CARRAY
			case EXPR_TYPE_SHORT:	// as short
			case EXPR_TYPE_INTGER:	// as Intger
				printf("%d\t",va_arg(va,int));
				break;
			case EXPR_TYPE_LONG:
				printf("%ld\t",(long)(va_arg(va,long)));
				break;
			default:
				printf("unsupported !");
		}		
	}
	printf("\n");
	fflush(stdout);
	
	return ret;
}