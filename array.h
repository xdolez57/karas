#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include <stdlib.h>

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

int  array_init(t_array	*array,
                int      size_x,
                int      size_y,
                char    *array_init,
                int      init_size
		);

void array_transpose(t_array *array);

void array_mirror_lr(t_array *array);

void array_mirror_ud(t_array *array);

void array_rotate_r(t_array *array);

void array_rotate_l(t_array *array);

void array_selectItem(t_array *array,
                      int      x,
                      int      y
                      );

void array_print(t_array *array);

#endif  /* __ARRAY_H__ */
