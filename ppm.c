#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ppm.h"

void ppm_create_buffer(pixmap *pm, int width, int height){
  pm->pixels = calloc(sizeof(pixel),width*height);
  pm->width = width;
  pm->height = height;
  int i;
  for(i = 0; i < height * width; i++){
    pm->pixels[i].r = 0;
    pm->pixels[i].g = 0;
    pm->pixels[i].b = 0;
  }
}

void ppm_save_image(pixmap *pm, char *filename){
  FILE *f = fopen(filename,"wb");
  fprintf(f,"P6\n%i %i\n255\n", pm->width, pm->height);
  int i;
  for(i = 0; i < pm->width*pm->height; i++){
    fprintf(f,"%c",pm->pixels[i].r);
    fprintf(f,"%c",pm->pixels[i].g);
    fprintf(f,"%c",pm->pixels[i].b);
  }
  fclose(f);
}

void ppm_fill_rect(pixmap *pm, int x, int y, int w, int h, pixel *p){
  int i,j;
  long int location;
  for(i = y; i < y+h; i++)
  for(j = x; j < x+w; j++){
    location = j + (i * pm->width);
    pm->pixels[location].r = p->r;
    pm->pixels[location].g = p->g;
    pm->pixels[location].b = p->b;
  }
}
