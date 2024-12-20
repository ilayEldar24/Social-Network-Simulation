#ifndef Member_H
#define Member_H
using namespace std;
#include "Feed.h"
#include "FanPage.h"
#include "SystemExc.h"
#include "FacebookObj.h"
class FanPage;
class Member : public Facebook_Obj{
private:
	
	int year, month, day;//date of birth

public:
	//done
	Member(const string& name, int year1, int month1, int day1);
	Member() = default;
	virtual const string getName()const;
	void showTenUpdated() const;
	virtual void ShowFans()const;
	
	
};
#endif




