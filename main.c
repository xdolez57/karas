#include <stdio.h>
#include <stdlib.h>

#define ARRAY_X 5
#define ARRAY_Y 5
#define ARRAY_STR "4911881785088516338545977"

#define KEY1 "25558361457"

#define diagFF(cond) {if(cond) {printf("Runtime error!\n"); return -1;}}
//#define diagFF(cond) cond;

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

int init(t_array *array, int size_x, int size_y, char *array_init, int init_size) {

  if (init_size < (size_x * size_y)) {
    return -1;
  }

  array->data = malloc(sizeof(t_item) * size_x * size_y);
  if (array->data == NULL) {
    return -1;
  }

  array->size_x = size_x;
  array->size_y = size_y;

  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;
  for (int j = 0, k = 0; j < array->size_y; j++) {
    for (int i = 0; i < array->size_x; i++, k++) {
      p_data[i][j].num   = (int)(array_init[k] - '0');
      p_data[i][j].valid = 0;
    }
  }

  return 0;
}

void print(t_array *array) {
  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;
  for (int j = 0; j < array->size_y; j++) {
    for (int i = 0; i < array->size_x; i++) {
      printf("%d ", p_data[i][j].num);
    }
    printf("\n");
  }
}

int main(void)
{
  t_array array;

  diagFF(init(&array, ARRAY_X, ARRAY_Y, ARRAY_STR, (int)(sizeof(ARRAY_STR) / sizeof(char))));
  print(&array);
  free((void *)array.data);

  return 0;
}

