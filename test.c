#include <stdlib.h>
#include <time.h>

#include "ppm.h"

#define STEP 10 // Tweak these to change the size and spacing of the squares in the grid
#define PSIZE 8

void draw_random(pixmap *pm){
  int i, j, g;
  pixel p;
  for(i = 0; i < pm->height; i+=STEP)
  for(j = 0; j < pm->width; j+=STEP){
    g = rand() % 255;
    p.r = g % 0x01; // tweak these to change the "overall color" of the image
    p.g = g % 0x3F;
    p.b = g % 0xA0;
    ppm_fill_rect(pm, j, i, PSIZE, PSIZE, &p);
  }
}

int main(void){
  srand(time(0));
  pixmap pm; 
  ppm_create_buffer(&pm, 1920, 1080);
  
  draw_random(&pm);

  ppm_save_image(&pm, "test.ppm");
  return 0;
}
