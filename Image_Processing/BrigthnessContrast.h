#pragma once
#include "ImageProcessing.h"
#include "Image.h"
class BrigthnessContrast: public ImageProcessing
{
public:
	BrigthnessContrast();
	BrigthnessContrast(float, float);

	void process(const Image& src, Image& dst);

private:
	float gain, bias;
};

