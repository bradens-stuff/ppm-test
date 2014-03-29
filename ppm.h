typedef struct{
  int r : 8;
  int g : 8;
  int b : 8;
} pixel, ppm_pixel;

typedef struct{
  pixel *pixels;
  int width;
  int height;
} pixmap, ppm_pixmap;
  
void ppm_create_buffer(pixmap *pm, int width, int height);
void ppm_save_image(pixmap *pm, char *filename);
void ppm_fill_rect(pixmap *pm, int x, int y, int w, int h, pixel *p);
