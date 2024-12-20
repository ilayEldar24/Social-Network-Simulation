#define _CRT_SECURE_NO_WARNINGS

#include "FanPage.h"


FanPage::FanPage(const string name1) :Facebook_Obj(name1) {};
//alternative impl to the base conv
void FanPage::ShowFans()const
{
	if (units.size() == 0)
	{
		cout << "There is no fans to this Fan Page\n";
	}
	else
	{
		cout << "Fans of " << Name << " :" << "\n";
		Facebook_Obj(*this).ShowFriends();

	}



}



