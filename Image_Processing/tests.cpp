#include "Image.h"
#include "ImageProcessing.h"
#include <assert.h>
#include "BrigthnessContrast.h"
#include "GammaCorrection.h"
void tests() {
	Size s1(0, 0);
	Image I1(s1);
	Image I2(s1);
	Image I3(s1);
	Image I4(s1);
	assert(I1.load("F:/Coding/OOP/Image_Processing/feep.pgm") == true);
	assert(I2.load("F:/Coding/OOP/Image_Processing/fee.pgm") == true);
	assert(I4.load("F:/Coding/OOP/Image_Processing/feep.pgm") == true);
	assert(I1.save("F:/Coding/OOP/Image_Processing/fee.pgm") == true);
	I3 = I1 + I2;
	assert(I1 == I3 - I2);
	assert(I4 == I1 * 3);
	cout << "Load and save ok" << endl;
	Image Em;
	assert(Em.isEmpty() == true);
	cout << "Empty ok" << endl;
	Point p1(10, 5);
	assert(p1.getX() == 10);
	assert(p1.getY() == 5);
	cout << "Point ok" << endl;
	Size s3(100, 23);
	Size s2(10, 10);
	assert(s3.getHeight() == 100);
	assert(s3.getWidth() == 23);
	assert(s3 != s2);
	s2 = s3;
	assert(s3 == s2);
	cout << "Size ok" << endl;
	Rectangle r1(p1, 10, 20);
	assert(r1.getX() == 10);
	assert(r1.getY() == 5);
	assert(r1.getLen() == 10);
	assert(r1.getWid() == 20);
	cout << "Rectangle ok" << endl;
	BrigthnessContrast BC1(2, 2);
	BC1.process(I1, I2);
	assert(I2 == I1*2+2);
	cout << "Brightness ok" << endl;
	GammaCorrection GC1(2);
	GC1.process(I1, I2);
	assert(I2 == I1 * I1);
	cout << "Gamma ok";


}
