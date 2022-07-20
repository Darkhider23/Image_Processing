#include "Image.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include <string>

using namespace std;

//empty constructor
Image::Image() {
	this->m_size = Size();
	//this->m_data = new char[0][0];
}

//default constructor
Image::Image(Size size) {
	this->m_size = size;
	//this->m_data = new char[size.getHeigth()][size.getWidth()];
	this->m_data = new unsigned char*[size.getHeight()];
	for (unsigned int i = 0; i < size.getHeight(); i++) {
		this->m_data[i] = new unsigned char[size.getWidth()];
	}
	for (unsigned int i = 0; i < size.getHeight(); i++) {
		for (unsigned int j = 0; j < size.getWidth(); j++) {
			this->m_data[i][j] = 0;
		}
	}
}

//destructor
Image::~Image() {
	release();
}
//copy constructor
Image::Image(const Image& other) {
	//assigning the size of other to this
	if( (*this == other) == false ){


		if (this->m_data != nullptr) {
			//deleting this data
			for (unsigned int i = 0; i < this->m_size.getHeight(); i++) {
				delete[] this->m_data[i];
			}
		}

		this->m_size = other.m_size;

		//recreating this data using the new size
		this->m_data = new unsigned char* [this->m_size.getHeight()];
		for (unsigned int i = 0; i < this->m_size.getHeight(); i++) {
			this->m_data[i] = new unsigned char[this->m_size.getWidth()];
		}

		//assigning the values from other's data to this' data
		for (unsigned int i = 0; i < this->m_size.getHeight(); i++) {
			for (unsigned int j = 0; j < this->m_size.getWidth(); j++) {
				this->m_data[i][j] = other.m_data[i][j];
			}
		}
	}
}

//assignment operator
Image& Image::operator=(const Image& other) {
	if (*this == other)
		return *this;
	if (this->m_data != nullptr) {
		//delete current data
		for (unsigned int i = this->m_size.getHeight()-1; i >0 ; i--) {
 			delete[] this->m_data[i];
		}
	}
	this->m_size = other.m_size;

	//making the new data with the new size

 	this->m_data = new unsigned char* [this->m_size.getHeight()];
	for (unsigned int i = 0; i < this->m_size.getHeight(); i++) {
		this->m_data[i] = new unsigned char[this->m_size.getWidth()];
	}
	//asigning the new data
	for (unsigned int i = 0; i < this->m_size.getHeight(); i++) {
		for (unsigned int j = 0; j < this->m_size.getWidth(); j++) {
			this->m_data[i][j] = other.m_data[i][j];
		}
	}
	return *this;
}

// + - adds two images of the same size
Image Image::operator+(const Image& img){
	
	if (this->m_size != img.m_size) {
		throw "The size of the images is different!";
	}
	else {
		Image result = *this;
		for (unsigned int i = 0; i < result.m_size.getHeight();i++) {
			for (unsigned int j = 0; j < result.m_size.getWidth(); j++) {
				unsigned int a = result.m_data[i][j], b = img.m_data[i][j];
				if (a + b > 255) result.m_data[i][j] = (unsigned char)255;
				else result.m_data[i][j] = (unsigned char)(a + b);
			}
		}
		return result;
	}
	;
	return Image{ Size(0,0) };

}

// - - subtract two images of the same size
Image Image::operator-(const Image& img) {

	if (this->m_size != i.m_size) {
		throw "The size of the images is different!";
	}
	else {
		Image result = *this;
		for (int j = 0; j < result.m_size.getHeight(); j++) {
			for (int k = 0; k < result.m_size.getWidth(); k++) {
				unsigned int a = result.m_data[j][k], b = i.m_data[j][k];
				if (a - b < 0) result.m_data[j][k] = (unsigned char)0;
				else result.m_data[j][k] = (unsigned char)(a - b);
			}
		}
		return result;
	}
	;
	return Image{ Size(0,0) };

}

// * - multiplies two images of the same size
Image Image::operator*(const Image& i) {

	if (this->m_size != i.m_size) {
		throw "The size of the images is different!";
	}
	else {
		Image result = *this;
		for (int j = 0; j < result.m_size.getHeight(); j++) {
			for (int k = 0; k < result.m_size.getWidth(); k++) {
				unsigned int a = result.m_data[j][k], b = i.m_data[j][k];
				if (a * b > 255) result.m_data[j][k] = (unsigned char)255;
				else result.m_data[j][k] = (unsigned char)(a * b);
			}
		}
		return result;
	}
	;
	return Image{ Size(0,0) };

}
//== operator
bool Image::operator==(const Image& other) {
	if (this->m_size != other.m_size)
		return false;
	else {
		for (int i = 0; i < this->m_size.getHeight(); i++) {
			for (int j = 0; j < this->m_size.getWidth(); j++) {
				if (this->m_data[i][j] != other.m_data[i][j])
					return false;
			}
		}
	}
	return true;
}
//!= operator
bool Image::operator!=(const Image& other) {
	if (this->m_size != other.m_size)
		return true;
	else {
		for (int i = 0; i < this->m_size.getHeight(); i++) {
			for (int j = 0; j < this->m_size.getWidth(); j++) {
				if (this->m_data[i][j] != other.m_data[i][j])
					return true;
			}
		}
	}
	return false;
}

//+ operator
Image Image::operator+(const int val) {
	Image newImage;
	newImage = *this;
	for (int i = 0; i < newImage.m_size.getHeight(); i++) {
		for (int j = 0; j < newImage.m_size.getWidth(); j++) {
			if (newImage.m_data[i][j] + val >= 256) newImage.m_data[i][j] = 255;
			else if (newImage.m_data[i][j] + val < 0) newImage.m_data[i][j] = 0;
			else newImage.m_data[i][j] = (unsigned char)((int)(newImage.m_data[i][j]) + val);
		}
	}
	// << newImage.m_size;
	return newImage;
}

//- operator
Image Image::operator-(const float val) {
	Image newImage;
	newImage = *this;
	
	for (int i = 0; i < newImage.m_size.getHeight(); i++) {
		for (int j = 0; j < newImage.m_size.getWidth(); j++) {
			if (newImage.m_data[i][j] - val >= 256) newImage.m_data[i][j] = 255;
			else if (newImage.m_data[i][j] - val < 0) newImage.m_data[i][j] = 0;
			else newImage.m_data[i][j] = (unsigned char)((int)(newImage.m_data[i][j]) - val);
		}
	}
	// << newImage.m_size;
	return newImage;
}
//* operator
Image Image::operator*(const float val) {
	Image newImage;
	newImage = *this;

	for (int i = 0; i < newImage.m_size.getHeight(); i++) {
		for (int j = 0; j < newImage.m_size.getWidth(); j++) {
			if (newImage.m_data[i][j] * val >= 256) newImage.m_data[i][j] = 255;
			else if (newImage.m_data[i][j] * val < 0) newImage.m_data[i][j] = 0;
			else newImage.m_data[i][j] = (unsigned char)((int)(newImage.m_data[i][j]) * val);
		}
	}
	// << newImage.m_size;
	return newImage;
}



//loading image from a file
bool Image::load(std::string imagePath) {
	ifstream f(imagePath);
	string aux;
	string fileType="";
	getline(f, fileType);
	if (fileType.compare("P2") != 0)return 0;
	getline(f, aux);
	int h, w;
	int maxValue;
	f >> w >> h >> maxValue;
	Image other(Size(h, w));
	*this = other;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			unsigned int exp;
			f >> exp;
			this->m_data[i][j] = (unsigned char) exp;
		}
	}

	return true;

}

//saving image to a file
bool Image::save(std::string imagePath) {
	ofstream f(imagePath);
	f << "P2\n";
	f << "#Farcas Alex\n";
	f << this->m_size.getWidth() << " " << this->m_size.getHeight() << "\n";
	f << "255\n";
	f << *this;
	f.close();
	return true;
}

//output operator
std::ostream& operator<<(std::ostream& os, const Image& dt) {
	std::cout << "(" << dt.m_size.getHeight() << "," << dt.m_size.getWidth() << ")" << endl;
	for (int i = 0; i < dt.m_size.getHeight(); i++) {
		int ok = 0;
		for (int j = 0; j < dt.m_size.getWidth(); j++) {
			os << setw(3) << unsigned(dt.m_data[i][j]);
		}
		if(ok==0)os<< "\n";
	}
	return os;
	
}
//check if the image is empty
bool Image::isEmpty() const {
	if (this->m_size == Size(0, 0)) {
		return true;
	}
	else {
		for (int i = 0; i < this->m_size.getHeight()-1; i++) {
			for (int j = 0; j < this->m_size.getHeight() - 1; j++) {
				if (this->m_data[i][j] != this->m_data[i][j + 1]) {
					return false;
				}
				if (this->m_data[i][j] != this->m_data[i+1][j]) {
					return false;
				}
				if (this->m_data[i][j] != this->m_data[i + 1][j+1]) {
					return false;
				}
			}
		}
	}
	return true;
}

unsigned char& Image::at(unsigned int y, unsigned int x) {

	return this->m_data[y][x];
}

unsigned char& Image::at(Point pot) {
	return this->m_data[pot.getY()][pot.getX()];
}

unsigned char* Image::row(int y) {
	return this->m_data[y];
}

bool Image::getROI(Image& roiImg, Rectangle roiRect) {
	if (roiRect.getX() + roiRect.getWid() >= roiImg.m_size.getWidth() || roiRect.getY() + roiRect.getLen() >= roiImg.m_size.getHeight()) {
		*this = Image(Size(0, 0));
		return false;
	}
	else {

		*this = Image(Size(roiRect.getLen(), roiRect.getWid()));
		for (int i = 0; i < roiRect.getLen(); i++) {
			for (int j = 0; j < roiRect.getWid(); j++) {
				this->m_data[i][j] = roiImg.m_data[i + roiRect.getY()][j + roiRect.getX()];
			}
		}
	}
	return true;
}
bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
	if (x + width >= roiImg.m_size.getWidth() || y + height >= roiImg.m_size.getHeight()) {
		*this = Image(Size(0, 0));
		return false;
	}
	else {
		*this = Image(Size(height, width));
		for (int i = 0; i <height; i++) {
			for (int j = 0; j < width; j++) {
				this->m_data[i][j] = roiImg.m_data[i + y][j + x];
			}
		}
	}
	return true;
}

void Image::release() {
	if (this->m_data != nullptr) {
		//deleting this data
		for (int i = 0; i < this->m_size.getHeight(); i++) {
			if (this->m_data[i] != nullptr)
				delete[] this->m_data[i];
		}

		delete[] this->m_data;
	}
}

