#ifndef Feed_H
#define Feed_H
#include "SystemExc.h"
#include <iostream>
#define CRT_SECURE_NO_WAARRINGS
#include "Status.h"
#include "imageStatus.h"
#include "videoStatus.h"
#include <vector>
#include <typeinfo>


using namespace std;

class Feed
{
private:
	vector<Status*> arrOfStatuses;
public:
	~Feed();
	void AddStatus(Status* newStat);
	void showLastTen() const;




};
#endif