
#include <stdlib.h>

void * brt_operator_new( size_t );

void* brt_operator_new( size_t __size)
{
	return malloc(__size);
}


