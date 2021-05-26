#ifndef __MAIN_H__
#define __MAIN_H__

#include "array.h"
#include "arraydef.h"
#include "display.h"
#include "ui.h"

#ifdef __MAIN_INTERNAL__

#define diagFF(cond) {if(cond) {printf("Runtime error!\n"); return -1;}}


static int  main_init(t_array *array);
static void main_run(t_array *array);

static void main_executeCmd(t_array *array,
                            t_cmd    command,
		            int      x,
		            int      y
		            );

#endif /* __MAIN_INTERNAL__ */
#endif /* __MAIN_H__ */
