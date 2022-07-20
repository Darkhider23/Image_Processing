#include  "ImageProcessing.h"
#include <iostream>
#include <filesystem>
#include "Image.h"
#include "tests.h"

/**
* Farcas Alex
* 01.04.2021
* Extra_Credits:Image Processing
*/
using namespace std;
int main() {
	Size s1(0, 0);
	Image I1(s1);
	I1.load("F:/Coding/OOP/Image_Processing/feep.pgm");
	cout << I1;

	tests();
}