#include "GammaCorrection.h"
#include <math.h>
GammaCorrection::GammaCorrection()
{
	this->gamma = 1;
}

GammaCorrection::GammaCorrection(int gamma)
{
	this->gamma = gamma;
}

void GammaCorrection::process(const Image& src, Image& dst)
{
	dst = src;
	for (unsigned int i = 0; i < dst.height(); i++) {
		for (unsigned int j = 0; j < dst.width(); j++) {
			float a = dst.at(i, j);
			if (pow(a, this->gamma) > 255)dst.at(i, j) = 255;
			else dst.at(i, j) = (unsigned char)(int)(pow(dst.at(i, j), this->gamma));
		}
	}
}