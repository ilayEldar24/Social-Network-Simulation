#ifndef FACEBOOK_H
#define FACEBOOK_H
#include "FanPage.h"
#include "Feed.h"
#include "Member.h"
#include "MineFunc.h"
#include "Status.h"
#include <vector>
#include "SystemExc.h"
#include "FacebookObj.h"

class Facebook {
private:
	vector<Facebook_Obj*> users;

public:
	~Facebook();
	//func 1
	void putMemInNet(Member* mem);

	//func 2
	void putFanPageInNet(FanPage* f);
	const Facebook& operator+=(FanPage* f);

	//func 3
	void AddStatus(const string& name, Status* status, int& cho);

	//fucn 4
	void printLastTen(const string& name, int& cho)const;


	//fucn 5
	void showMostUpdated(const string& name)const;


	//func 6
	void connectThem(const string& name1, const string& name2);

	//func 7
	void unFriend(const string& name1, const string& name2);

	//func 8 
	void Add_Fan(const string& friend_name, const string& fanpage_name);


	//func 9
	void Delete_fan(const string& friend_name, const string& fanPageName);

	//func 10:
	void ShowEm()const;

	//func 11:
	void showHisFriend(int& cho, const string& name)const;

	//exception func
	void isNameAvailableMem(string str)noexcept(false);
	void isNameNotAvailableMem(string str) noexcept(false);
	void isNameAvailableFan(string str)noexcept(false);
	void isNameNotAvailableFan(string str)noexcept(false);


};
#endif
