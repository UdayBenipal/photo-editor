#include <utility>
#include <vector>
#include "sepia.h"

Sepia::Sepia(Image *img): Decorator{img} {}

void Sepia::render(PPM &ppm) {
	img->render(ppm);
	std::vector<Pixel> &img_p = ppm.getPixels();
	int len = img_p.size();
	Pixel p;

	for(int i = 0; i < len; ++i) {
		p = img_p.at(i);

		img_p.at(i).r = p.r *.393 + p.g * .769 + p.b * .189;
		if(img_p.at(i).r > colourMax) img_p.at(i).r = colourMax;

		img_p.at(i).g = p.r *.349 + p.g * .686 + p.b * .168;
		if(img_p.at(i).g > colourMax) img_p.at(i).g = colourMax;

		img_p.at(i).b = p.r *.272 + p.g * .534 + p.b * .131;
		if(img_p.at(i).b > colourMax) img_p.at(i).b = colourMax;
	}
}

