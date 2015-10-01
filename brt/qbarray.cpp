/**
 * this file is part of llvm-qbc
 */

/*
    array support for internal data struct

    Copyright (C) 2012  microcai <microcai@fedoraproject.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <memory.h>
#include <stdlib.h>
#include "qbc.h"

extern "C" void btr_qbarray_new(QBArray * array, size_t element)
{
	memset(array,0,sizeof(QBArray));

	array->capacity = 0;
	array->elementsize = element;
	// ROUNDUP
	array->stride = (element / sizeof(int) + 1 ) * sizeof(int);
}

extern "C" void btr_qbarray_free(QBArray * array)
{
	free(array->ptr);
	memset(array,0,sizeof(*array));
}

extern "C" void * btr_qbarray_at(QBArray * array,size_t index)
{
	// 没有内存就分配呗
	if(!array->ptr || array->capacity < index * array->stride){
		//多分配32个
		array->capacity = (index + 32)*array->stride;
		array->ptr =  realloc(array->ptr,array->capacity);
	}
	return ((unsigned char*)array->ptr) + ((index - 1)  * array->stride);
}
