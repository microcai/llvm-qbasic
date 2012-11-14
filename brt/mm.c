
#include <stdlib.h>

void * brt_operator_new( size_t );
void brt_ooperator_delete( void*);

void* brt_operator_new( size_t __size)
{
	return malloc(__size);
}

void brt_ooperator_delete(void* __ptr)
{
	free(__ptr);
}

