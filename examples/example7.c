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
    g = rand() % 255; // grey
    // pixel
    p.r = g % 0x01; // tweak these to change the "overall color" of the image
    p.g = g % 0x3F;
    p.b = g % 0xA0;
    p.a = 0xFF / 2; // pixel alpha at 50%
    // shade
    s.r = 0x00;
    s.g = 0x00;
    s.b = 0x00;
    if(i < pm->height / 3) { // top third
      s.a = 0xFF / 2;
    } else if(i > (pm->height / 3) * 2) { // bottom third
      s.a = 0xFF / 8;
      s.r = s.g = s.b = 0xFF;
    } else { // mid section
      s.a = 0;
    }
    ppm_fill_rect(pm, j, i, PSIZE, PSIZE, &p, &s);
  }
}

int main(void){
  srand(time(0));
  pixmap pm; 
  ppm_create_buffer(&pm, 1920, 1080);
  
  draw_random(&pm);

  ppm_save_image(&pm, "7.ppm");
  printf("Generated file 7.ppm\n");
  return 0;
}
