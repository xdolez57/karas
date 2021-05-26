#include "main.h"
#include "ui.h"

#define ARRAY_X 5
#define ARRAY_Y 5
#define ARRAY_STR "4911881785088516338545977"

#define KEY1 "25558361457"

#define GPS_LENGTH 12

#define diagFF(cond) {if(cond) {printf("Runtime error!\n"); return -1;}}

char gps[GPS_LENGTH];

void gpsInit(void)
{
  int i;

  for (i = 0; i < GPS_LENGTH; i++) {
    gps[i] = ' ';
  }
}

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
  for (int i = 0, k = 0; i < array->size_y; i++) {
    for (int j = 0; j < array->size_x; j++, k++) {
      p_data[i][j].num   = (int)(array_init[k] - '0');
      p_data[i][j].valid = 1;
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

void selectItem(t_array *array,
                int      x,
                int      y) {
  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;
  p_data[x][y].valid = 0;
}

void print(t_array *array) {
  printGPS();
  printKey();
  printf("\n");
  printArray(array);
}

void printGPS(void) {
  printf("GPS: N49°11.853 E16°38.418\n");
  printf("GPS final: N49 1%c.%c%c%c%c%c, E16 3%c.%c%c%c%c%c\n", gps[0], gps[1], gps[2], gps[3], gps[4], gps[5],
                                                                gps[6], gps[7], gps[8], gps[9], gps[10], gps[11]);
}

void printKey(void) {
  printf("Key: %s\n", KEY1);
}

void printArray(t_array *array) {
  t_item (*p_data)[array->size_x] = (t_item (*)[array->size_x])array->data;

  for (int i = 0; i < array->size_y; i++) {
    for (int j = 0; j < array->size_x; j++) {
      if (p_data[i][j].valid) {
	printf("%d ", p_data[i][j].num);
      }
      else {
	printf("  ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void executeOperation(t_array *array,
                      t_cmd    command,
		      int      x,
		      int      y)
{
  switch (command) {
    case cmd_rotate_left:
      rotate_l(array);
      break;

    case cmd_rotate_right:
      rotate_r(array);
      break;


    case cmd_select:
      selectItem(array, x, y);
      break;

    default:
      break;
  }

  if (command != cmd_quit) {
    print(array);
  }
}

int main(void)
{
  t_array array;
  t_cmd command = cmd_no_command;
  int x, y;

  gpsInit();
  diagFF(init(&array, ARRAY_X, ARRAY_Y, ARRAY_STR, (int)(sizeof(ARRAY_STR) / sizeof(char))));
  print(&array);

  while (command != cmd_quit) {
    getCmd(&command, &x, &y);
    executeOperation(&array, command, x, y);
  }

  free((void *)array.data);

  return 0;
}

