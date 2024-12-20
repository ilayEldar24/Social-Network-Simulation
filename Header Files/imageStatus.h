#ifndef IMG_H
#define IMG_H
#include "status.h"

class ImageStatus : public Status
{
protected:
	string imgFileName;
public:
	ImageStatus() = default;
	ImageStatus(const string& status, const string& fileName);
	void setImg(const string fileName);
	void printStatus();
	string getImage();
};
#endif