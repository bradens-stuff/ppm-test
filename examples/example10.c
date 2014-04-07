#include <stdlib.h>
#include <time.h>

#include "../src/ppm.h"

#define STEP 20  // controls the gap between each square on the grid
#define PSIZE 20 // controls the size of each square on the grid
//                 try STEP 10; PSIZE 8

void draw_random(pixmap *pm, int blue, int pblue, int probability, int padding){
  int i, j;
  pixel p;
  pixel s; //shadow
  for(i = 0; i < pm->height; i+=STEP)
  for(j = 0; j < pm->width; j+=STEP){
    if(rand() % 100 < probability){
      p.r = 0x00; 
      p.g = 0x00;
      p.b = pblue;
      p.a = 0xFF / 4;

      s.r = 0x00;
      s.g = 0x00;
      s.b = 0x33;
      s.a = (0xFF / 4) * 3;
      ppm_fill_rect(pm, j, i, PSIZE, PSIZE, &p, &s);
      // pixel
      p.r = 0x00; 
      p.g = 0x00;
      p.b = blue;
      p.a = 0xFF; 
      // shade
      s.a = 0;
      ppm_fill_rect(pm, j+padding, i+padding, PSIZE-padding*2, PSIZE-padding*2, &p, &s);
    }
  }
}

int main(void){
  srand(time(0));
  pixmap pm; 
  ppm_create_buffer(&pm, 1920, 1080);
  
  draw_random(&pm, 0x33, 0x33, 100, 0);
  draw_random(&pm, 0x55, 0x33, 40,  2);
  draw_random(&pm, 0x77, 0x55, 60,  2);
  draw_random(&pm, 0x99, 0x77, 30,  2);

  ppm_save_image(&pm, "example10.ppm");
  return 0;
}
