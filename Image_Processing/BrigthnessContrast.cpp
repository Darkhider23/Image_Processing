#include "BrigthnessContrast.h"

BrigthnessContrast::BrigthnessContrast() {
	this->gain = 1;
	this->bias = 0;
}

BrigthnessContrast::BrigthnessContrast(float alpha, float beta) {
	this->gain = alpha;
	this->bias = beta;
}

void BrigthnessContrast::process(const Image& src, Image& dst) {
	dst = src;
	for (unsigned int i = 0; i < dst.height(); i++) {
		for (unsigned int j = 0; j < dst.width(); j++) {
			float a = dst.at(i, j);
			if (a * this->gain + this->bias > 255) dst.at(i, j) = 255;
			else if(a * this->gain + this->bias < 0) dst.at(i, j) = 0;
			else dst.at(i, j) = (unsigned char)((int)(this->gain * dst.at(i,j)+this->bias));
		}
	}
}