#include "imageStatus.h"


ImageStatus::ImageStatus(const string& status1, const string& fileName1) : Status(status1)
{
	imgFileName = fileName1;
}

void ImageStatus::setImg(const string fileName)
{
	imgFileName = fileName;
}

void ImageStatus::printStatus()
{
	cout << status << "\n";
	cout << "Path to image file : \t\t" << imgFileName << "\n";
	cout << "Posted at \t:";
	cout << day << "/" << month << "/" << year << "\n";
}

string ImageStatus::getImage()
{
	return imgFileName;
}
