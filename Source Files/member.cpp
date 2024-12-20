#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include "Member.h"
#include "MineFunc.h"
#include "Feed.h"
#include "Status.h"
#include "FanPage.h"
#include <stdbool.h>
#include <vector>

Member::Member(const string& name, int year1, int month1, int day1):Facebook_Obj(name)
{
	
	year = year1;
	month = month1;
	day = day1;
}

const string Member::getName()const
{
	return(Facebook_Obj(*this).getName());
}
void Member::showTenUpdated()const
{
	if (units.empty())
	{
		cout << "Member : " << (*this).getName() << " has no friends\n";
	}
	else
	{
		
		for (int i = 0; i < units.size(); i++)
		{
			Member* temp = dynamic_cast<Member*>(units[i]);
			if(temp)
				this->units[i]->ShowTenStatuss();
			
		}
		
	}
}

//alternative impl to the base conv
void Member::ShowFans()const
{
	if (units.size() == 0)
	{
		cout << "There is no friends to this member\n";
	}
	else
	{
		cout << "Friends of " << Name << " :" << "\n";
		Facebook_Obj(*this).ShowFriends();

	}
}
