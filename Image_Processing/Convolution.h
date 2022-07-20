#pragma once
#include "ImageProcessing.h"
#include "Image.h"
class ImageConvolution :public ImageProcessing {
public:
	ImageConvolution();
	ImageConvolution(Image);

	void process(Image& src, Image& dst);
private:
	Image Kernel;
};