#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <stdio.h>

#include "array.h"
#include "arraydef.h"

#define GPS_LENGTH 12

void display_init(void);
void display_print(t_array *array);

#ifdef __DISPLAY_INTERNAL__

static void printGPS(void);
static void printKey(void);

#endif /* __DISPLAY_INTERNAL__ */
#endif /* __DISPLAY_H__ */
