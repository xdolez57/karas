#ifndef __MAIN_H__
#define __MAIN_H__

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

void print(	t_array	*array);

#endif
