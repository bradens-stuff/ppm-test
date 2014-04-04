#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../src/ppm.h"

#define STEP 1  // controls the gap between each square on the grid
#define PSIZE 1 // controls the size of each square on the grid
//                 try STEP 10; PSIZE 8

void draw_random(pixmap *pm){
  int i, j, g;
  pixel p;
  pixel s; //shadow
  for(i = 0; i < pm->height; i+=STEP)
  for(j = 0; j < pm->width; j+=STEP){
    g = rand() % 0xFF;
    // pixel
    p.r = g;
    p.g = g;
    p.b = g;
    p.a = 0xFF; // pixel alpha at 50%
    // shade
    s.r = 0;
    s.g = 0;
    s.b = 0;
    s.a = 0;
    ppm_fill_rect(pm, j, i, PSIZE, PSIZE, &p, &s);
  }
}

int main(void){
  srand(time(0));
  pixmap pm; 
  ppm_create_buffer(&pm, 1920, 1080);
  
  draw_random(&pm);

  ppm_save_image(&pm, "2.ppm");
  printf("Generated file 2.ppm\n");
  return 0;
}
