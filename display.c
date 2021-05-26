#define __DISPLAY_INTERNAL__

#include "display.h"

static char gps[GPS_LENGTH];
static int  idx;

void display_init(void)
{
  int i;

  for (i = 0; i < GPS_LENGTH; i++)
  {
    gps[i] = ' ';
  }

  idx = 0;
}

void display_print(t_array *array)
{
  printGPS();
  printKey();
  printf("\n");
  array_print(array);
}

void display_setNextNumber(int n)
{
  gps[idx++] = '0' + n;
}

static void printGPS(void)
{
  printf("GPS: N49°11.853 E16°38.418\n");
  printf("GPS final: N49 1%c.%c%c%c%c%c, E16 3%c.%c%c%c%c%c\n", gps[0], gps[1], gps[2], gps[3], gps[4], gps[5],
                                                                gps[6], gps[7], gps[8], gps[9], gps[10], gps[11]);
}

static void printKey(void)
{
  printf("Key: %s\n", KEY1);
}


