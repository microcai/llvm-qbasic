#pragma once
/*
    main header file
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

#include <stdio.h>

#ifdef __linux__
#define SYSTEM_NAME "Linux"
#elif _WIN32
#define SYSTEM_NAME "Windows"
#endif

#define VERSION "0.1"

char *replace (char *);         /* replace escape characters */

typedef struct QBArray{
	void*		ptr; // pointer to the allocated address
	size_t		elementsize;// size of the element
	size_t		stride; // size to move the pointer to touch the next element
	size_t		capacity; // the capacity of the allocated memory
}QBArray;
