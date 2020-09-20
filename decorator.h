#ifndef DECORATOR_H
#define DECORATOR_H
#include "image.h"

class Decorator: public Image {
protected:
  Image *img;
public:
  Decorator(Image *img);
  virtual ~Decorator() override;
};

#endif
