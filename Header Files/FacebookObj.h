#ifndef FACEBOOK_OBJ_H
#define FACEBOOK_OBJ_H
#include <vector>
#include <string>
#include "Feed.h"
#include <typeinfo>
using namespace std;

class Facebook_Obj
{
protected:
	string Name;
	Feed feed;
	vector<Facebook_Obj*> units;
public:
	Facebook_Obj() = default;
	Facebook_Obj(const string& name);
	virtual const string getName()const;//
	virtual void setStatus(Status* status);//
	virtual void ShowTenStatuss()const;
	virtual bool isNotFriend(Facebook_Obj* other) const;//
	virtual void makeFriendship(Facebook_Obj* other);
	virtual void ShowFriends()const;
	virtual void deleteFriend(Facebook_Obj* other);
	virtual int getNumOfFriends()const;
	friend bool operator<(const Facebook_Obj& ob1, const Facebook_Obj& ob2);
	friend bool operator>(const Facebook_Obj& ob1, const Facebook_Obj& ob2);
	friend void operator+=(Facebook_Obj& ob1, Facebook_Obj& ob2);
	

	
};
#endif
