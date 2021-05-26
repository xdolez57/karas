#include "main.h"
#include "ui.h"

#define ARRAY_X 5
#define ARRAY_Y 5
#define ARRAY_STR "4911881785088516338545977"

#define KEY1 "25558361457"

#define CMD_LENGTH 3

#define diagFF(cond) {if(cond) {printf("Runtime error!\n"); return -1;}}

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

void transpose(t_array *array) {
  t_item tmp_array[array->size_x][array->size_y];

  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;

  for (int j = 0; j < array->size_y; j++) {
    for (int i = 0; i < array->size_x; i++) {
      tmp_array[i][j] = p_data[j][i];
    }
  }

  for (int j = 0; j < array->size_y; j++) {
    for (int i = 0; i < array->size_x; i++) {
      p_data[i][j] = tmp_array[i][j];
    }
  }
}

void mirror_lr(t_array *array) {
  t_item tmp_array[array->size_x][array->size_y];

  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;

  for (int j = 0; j < array->size_y; j++) {
    for (int i = 0; i < array->size_x; i++) {
      tmp_array[i][j] = p_data[array->size_x - i - 1][j];
    }
  }

  for (int j = 0; j < array->size_y; j++) {
    for (int i = 0; i < array->size_x; i++) {
      p_data[i][j] = tmp_array[i][j];
    }
  }
}

void mirror_ud(t_array *array) {
  t_item tmp_array[array->size_x][array->size_y];

  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;

  for (int j = 0; j < array->size_y; j++) {
    for (int i = 0; i < array->size_x; i++) {
      tmp_array[i][j] = p_data[i][array->size_y - j - 1];
    }
  }

  for (int j = 0; j < array->size_y; j++) {
    for (int i = 0; i < array->size_x; i++) {
      p_data[i][j] = tmp_array[i][j];
    }
  }
}

void rotate_r(t_array *array) {
  transpose(array);
  mirror_lr(array);
}

void rotate_l(t_array *array) {
  mirror_lr(array);
  transpose(array);
}

void print(t_array *array) {
  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;
  for (int j = 0; j < array->size_y; j++) {
    for (int i = 0; i < array->size_x; i++) {
      printf("%d ", p_data[i][j].num);
    }
    printf("\n");
  }
  printf("\n");
}


int main(void)
{
  t_array array;
  t_cmd command = cmd_no_command;
  int x, y;

  diagFF(init(&array, ARRAY_X, ARRAY_Y, ARRAY_STR, (int)(sizeof(ARRAY_STR) / sizeof(char))));

  while (command != cmd_quit) {
    getCmd(&command, &x, &y);
    printf("command: %d, x: %d, y: %d\n", (int)command, x, y);
  }

  print(&array);
  free((void *)array.data);

  return 0;
}

