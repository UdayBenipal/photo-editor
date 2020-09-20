#include <utility>
#include <vector>
#include "rotate.h"

Rotate::Rotate(Image *img): Decorator{img} {}

void Rotate::render(PPM &ppm) {
	img->render(ppm);
	int &width = ppm.getWidth();
	int &height = ppm.getHeight();
	std::vector<Pixel> &img_p = ppm.getPixels();
	std::swap(width, height);

	std::vector<Pixel> temp = img_p;

	for(int i = 0; i < height; ++i) {
		for(int j = 0; j < width; ++j) {
			img_p.at(j+(i*width)) = temp.at(height * (width-1-j) + i);
		}
	}
}
