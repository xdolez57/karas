#define __DISPLAY_INTERNAL__

#include "display.h"

char gps[GPS_LENGTH];

void display_init(void)
{
  int i;

  for (i = 0; i < GPS_LENGTH; i++) {
    gps[i] = ' ';
  }
}

void display_print(t_array *array) {
  printGPS();
  printKey();
  printf("\n");
  array_print(array);
}

static void printGPS(void) {
  printf("GPS: N49°11.853 E16°38.418\n");
  printf("GPS final: N49 1%c.%c%c%c%c%c, E16 3%c.%c%c%c%c%c\n", gps[0], gps[1], gps[2], gps[3], gps[4], gps[5],
                                                                gps[6], gps[7], gps[8], gps[9], gps[10], gps[11]);
}

static void printKey(void) {
  printf("Key: %s\n", KEY1);
}


