#ifndef FLIP_H
#define FLIP_H
#include "decorator.h"

class Flip: public Decorator {
public:
  Flip(Image *img);
  void render(PPM &ppm) override;
};

#endif
