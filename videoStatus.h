#ifndef VID_H
#define VID_H
#include "status.h"
class VideoStatus : public Status
{
protected:
	string vidFileName;
public:
	VideoStatus() = default;
	VideoStatus(const string& status, const string& fileName);
	void setVideo(const string fileName);
	void printStatus();
	string getVideo();
	
};
#endif