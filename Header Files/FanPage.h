#ifndef FanPage_H
#define FanPage_H
using namespace std;
#include "Member.h"
#include "Status.h"
#include "SystemExc.h"
#include <vector>
#include "FacebookObj.h"
class Facebook_Obj;
class FanPage: public Facebook_Obj {


public:
	FanPage() = default;
	FanPage(const string name1);
	void ShowFans()const;
	
};
#endif
