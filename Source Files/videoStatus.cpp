#include "videoStatus.h"


VideoStatus::VideoStatus(const string& status1, const string& path1) : Status(path1)
{
	vidFileName = path1;
}

void VideoStatus::setVideo(const string fileName)
{
	vidFileName = fileName;
}
void VideoStatus::printStatus()
{
	cout << status << "\n";
	cout << "Path to video file : \t\t" << vidFileName << "\n";
	cout << "Posted at \t:";
	cout << day << "/" << month << "/" << year << "\n";
}

string VideoStatus::getVideo()
{
	return vidFileName;
}