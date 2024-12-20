#ifndef SYSTEMEX_H
#define SYSTEMEX_H
//exceptions
#include <iostream>
using namespace std;
//base
class FaceBookExc : public exception
{
public:
	virtual void what() { cout << "Eror ! Try again\n"; };

};


class ChoiceExp :public FaceBookExc
{
public:
	int x=1;
	int y = 12;
	ChoiceExp() = default;
	ChoiceExp(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	void what()
	{
		
		cout << "\nInvalid choice !\n"<<"Choose number between "<<x<<" - "<<y<<" Please try again !" << endl;
	}
};
class NotANumberExp :public ChoiceExp
{
public:
	NotANumberExp(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	void what()
	{
		cin.clear();
		cout << "\nInvalid choice !\nPlease choose number between " << x << " - " << y << " Please try again !" << endl;
	}


};
class DateeExp :public FaceBookExc
{
public:
	void what()
	{
		
		cout << "Invalid Date !\nTry Again\n" << endl;
	}
		
	

};
class MemberNameExp :public FaceBookExc
{
public:
	string name;
	MemberNameExp(string& name1)
	{
		name = name1;
	}
	void what()
	{
		cout << "\nThe Member name " << name << " is already in used\nTry again\n" << endl;;
	}
	
};
class MemberFriendExp :public FaceBookExc
{
public:
	void what()
	{
		cout << "Member Can not be a friend of himself\n Try Again\n" << endl;
	}

};
class FanPageNameExp :public FaceBookExc
{
public:
	string name;
	FanPageNameExp(string& name1)
	{
		name = name1;
	}
	void what()
	{
		cout << "\nThe Fan Page name : " << name << " is already in used\nTry again\n";
	}
};
class UserIsntInNetExp :public FaceBookExc
{
public:
	string name;
	UserIsntInNetExp(const string& name1)
	{
		name = name1;
	}
	void what()
	{
		cout << "\nThe user name : " << name << " isnt in Net\nTry again\n";
	}
};
class FanPageIsntInNetExp :public FaceBookExc
{
public:
	string name;
	FanPageIsntInNetExp(const string& name1)
	{
		name = name1;
	}
	void what()
	{
		cout << "\nThe fan page name : " << name << " isnt in Net\nTry again\n";
	}
};


#endif