#define __MAIN_INTERNAL__

#include "main.h"

int main(void)
{
  t_array array;

  diagFF(main_init(&array));
  main_run(&array);

  free((void *)array.data);

  return 0;
}

static int main_init(t_array *array)
{
  display_init();
  diagFF(array_init(array, ARRAY_X, ARRAY_Y, ARRAY_STR, (int)(sizeof(ARRAY_STR) / sizeof(char))));

  return 0;
}


static void main_run(t_array *array)
{
  t_cmd command = cmd_no_command;
  int x, y;

  display_print(array);

  while (command != cmd_quit)
  {
    ui_getCmd(&command, &x, &y);
    main_executeCmd(array, command, x, y);
  }
}

static void main_executeCmd(t_array *array,
                            t_cmd    command,
		            int      x,
		            int      y)
{
  switch (command)
  {
    case cmd_rotate_left:
      array_rotate_l(array);
      display_print(array);
      break;

    case cmd_rotate_right:
      array_rotate_r(array);
      display_print(array);
      break;


    case cmd_select:
      array_selectItem(array, x, y);
      display_print(array);
      break;

    case cmd_quit:
      break;

    default:
      break;
  }
}

