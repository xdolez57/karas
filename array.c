#define __ARRAY_INTERNAL__

#include "array.h"

int array_init(t_array *array, int size_x, int size_y, char *array_init)
{
  array->data = malloc(sizeof(t_item) * size_x * size_y);

  if (array->data == NULL)
  {
    return -1;
  }

  array->size_x = size_x;
  array->size_y = size_y;

  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;

  for (int i = 0, k = 0; i < array->size_y; i++)
  {
    for (int j = 0; j < array->size_x; j++, k++)
    {
      p_data[i][j].num   = (int)(array_init[k] - '0');
      p_data[i][j].valid = 1;
    }
  }

  return 0;
}

void array_transpose(t_array *array)
{
  t_item tmp_array[array->size_x][array->size_y];

  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;

  for (int j = 0; j < array->size_y; j++)
  {
    for (int i = 0; i < array->size_x; i++)
    {
      tmp_array[i][j] = p_data[j][i];
    }
  }

  for (int j = 0; j < array->size_y; j++)
  {
    for (int i = 0; i < array->size_x; i++)
    {
      p_data[i][j] = tmp_array[i][j];
    }
  }
}

void array_mirror_lr(t_array *array)
{
  t_item tmp_array[array->size_x][array->size_y];

  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;

  for (int j = 0; j < array->size_y; j++)
  {
    for (int i = 0; i < array->size_x; i++)
    {
      tmp_array[i][j] = p_data[array->size_x - i - 1][j];
    }
  }

  for (int j = 0; j < array->size_y; j++)
  {
    for (int i = 0; i < array->size_x; i++)
    {
      p_data[i][j] = tmp_array[i][j];
    }
  }
}

void array_mirror_ud(t_array *array)
{
  t_item tmp_array[array->size_x][array->size_y];

  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;

  for (int j = 0; j < array->size_y; j++)
  {
    for (int i = 0; i < array->size_x; i++)
    {
      tmp_array[i][j] = p_data[i][array->size_y - j - 1];
    }
  }

  for (int j = 0; j < array->size_y; j++)
  {
    for (int i = 0; i < array->size_x; i++)
    {
      p_data[i][j] = tmp_array[i][j];
    }
  }
}

void array_rotate_r(t_array *array)
{
  array_mirror_lr(array);
  array_transpose(array);
}

void array_rotate_l(t_array *array)
{
  array_transpose(array);
  array_mirror_lr(array);
}

void array_selectItem(t_array *array,
                int      x,
                int      y)
{
  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;
  p_data[x][y].valid = 0;
  display_setNextNumber(p_data[x][y].num);
}

void array_print(t_array *array)
{
  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;

  for (int i = 0; i < array->size_y; i++)
  {
    for (int j = 0; j < array->size_x; j++)
    {
      if (p_data[i][j].valid)
      {
	printf("%d ", p_data[i][j].num);
      }
      else
      {
	printf("  ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

