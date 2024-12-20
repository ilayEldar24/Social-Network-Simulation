#ifndef Status_H
#define Status_H
#define _CRT_SECURE_NO_WAARRINGS
#include <string>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include "SystemExc.h"
#include <ctime>
using namespace std;
class Status {
protected:
	string status;
	int year, month, day;
	int mins, hour;

public:
	//status
	Status() = default;
	Status(const string& status);
	void setStatus(const string str);
	const string getStatus() const;
	friend bool operator==(Status& st1,Status& st2);
	virtual void printStatus();

};
#endif
