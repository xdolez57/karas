#ifndef __UI_H__
#define __UI_H__

#include <stdio.h>

typedef enum
{
  cmd_no_command   = 0,
  cmd_rotate_right = 1,
  cmd_rotate_left  = 2,
  cmd_select       = 3,
  cmd_quit         = 4
} t_cmd;

void ui_getCmd(t_cmd *command,
               int   *x,
               int   *y
	       );

#endif /* __UI_H__ */
