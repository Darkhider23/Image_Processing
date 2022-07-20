#pragma once
#include "ImageProcessing.h"
#include "Image.h"
class GammaCorrection :public ImageProcessing {
public:
	GammaCorrection();
	GammaCorrection(int);

	void process(const Image& src, Image& dst);
private:
	float gamma;
};
