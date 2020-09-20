#include <utility>
#include <vector>
#include "flip.h"

Flip::Flip(Image *img): Decorator{img} {}

void Flip::render(PPM &ppm) {
	img->render(ppm);
	int &width = ppm.getWidth();
	int &height = ppm.getHeight();
	std::vector<Pixel> &imgp = ppm.getPixels();
	for(int i = 0; i < height; ++i) {
		for(int j = 0; j < width/2; ++j) {
			std::swap(imgp[j+(i*width)], imgp[(width-1-j)+(i*width)]);
		}
	}
}

