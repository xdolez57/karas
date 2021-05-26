#include "ui.h"

void getCmd(t_cmd *command, int *x, int *y)
{
  char command_raw, x_raw;

  printf(">>");
  scanf("%c %c%d", &command_raw, &x_raw, y);

  *x = x_raw - 'a';

  switch(command_raw)
  {
    case 'l':
    *command = cmd_rotate_left;
    break;
    
    case 'r':
    *command = cmd_rotate_right;
    break;

    case 's':
    *command = cmd_select;
    break;

    case 'q':
    *command = cmd_quit;
    break;

    default:
    printf("Unknown command!\n"\
           "Exiting the program...\n");

    *command = cmd_quit;
    break;
  }
}
