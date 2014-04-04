#include "ppm.h"
#include "alpha.h"

static void blend(unsigned char out[4], unsigned char fg[4], unsigned char bg[4]){
    unsigned int alpha = fg[3] + 1;
    unsigned int ialpha = 0xff - alpha;
    out[0] = (unsigned char)((alpha * fg[0] + ialpha * bg[0]) >> 8);
    out[1] = (unsigned char)((alpha * fg[1] + ialpha * bg[1]) >> 8);
    out[2] = (unsigned char)((alpha * fg[2] + ialpha * bg[2]) >> 8);
    out[3] = 0xff;
}

void alpha_blend(pixel *out, pixel *p1, pixel *p2){
  unsigned char fn[4] = {out->r, out->g, out->b, out->a};
  unsigned char bg[4] = {p1->r, p1->g, p1->b, p1->a};
  unsigned char fg[4] = {p2->r, p2->g, p2->b, p2->a};
  blend(fn, fg, bg);
  out->r = fn[0];
  out->g = fn[1];
  out->b = fn[2];
  out->a = fn[3];
}
