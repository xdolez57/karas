#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "array.h"

#define GPS_LENGTH 12

void display_init(void);
void display_print(t_array *array);
void display_setNextNumber(int n);

#ifdef __DISPLAY_INTERNAL__

#include <stdio.h>
#include <string.h>

#include "arraydef.h"

#define KEYLABEL "Key: "

static void printGPS(void);
static void printKey(void);
static void printStep(void);

#endif /* __DISPLAY_INTERNAL__ */
#endif /* __DISPLAY_H__ */
