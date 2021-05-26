#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

#include "ui.h"

typedef struct
{
  int num;
  int valid;
} t_item;

typedef struct
{
  t_item *data;
  int size_x;
  int size_y;
} t_array;

int init(	t_array	*array,
		int 	 size_x,
		int 	 size_y,
		char 	*array_init,
		int 	 init_size);

void transpose(	t_array	*array);
void mirror_lr(	t_array	*array);
void mirror_ud(	t_array	*array);

void rotate_r(	t_array	*array);

void selectItem(t_array *array,
                int      x,
                int      y);

void print(	t_array	*array);

void execute(   t_array *array,
                t_cmd command,
		int x,
		int y);

#endif  /* __MAIN_H__ */
