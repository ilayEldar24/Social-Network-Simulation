#define _CRT_SECURE_NO_WARNINGS
#include "Status.h"
#include "imageStatus.h"
#include "videoStatus.h"

Status::Status(const string& status)
{
	tm* St_time;
	this->status = status;
	time_t tim = time(0);
	St_time = gmtime(&tim);
	year = St_time->tm_year + 1900;
	month = St_time->tm_mon;
	day = St_time->tm_mday;
	hour = St_time->tm_hour;
	mins = St_time->tm_min;

}
void Status::setStatus(const string str)
{
	this->status = str;
}
const string Status::getStatus() const
{
	return(this->status);
}
void Status::printStatus()
{
	cout << status << "\n";
	cout << "Posted at \t:";
	cout << day << "/" << month << "/" << year;
}
