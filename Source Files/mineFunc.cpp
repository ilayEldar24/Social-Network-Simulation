#include "MineFunc.h"
#include "Member.h"
#include "facebook.h"
#include "SystemExc.h"


//main func

int printmenu()
{
	bool valid = false;
	int i;
	while (!valid)
	{
		try
		{
			string c;
			int choice;
			cout << "\nPress 1 : For add member\n\nPress 2 : for add fan page\n\nPress 3 : For add status for member or fan page\n\nPress 4 : For show the whole member's or fan page's status\n\nPress 5 : For show the feed of member\n\nPress 6 : To build a frienship\n\nPress 7 : To cancel a frinedship\n\nPress 8 : For add a fan to fan page\n\nPress 9 : To remove a fan from fan page\n\nPress 10 : For show all the members and fan pages in facebook\n\nPress 11 : For showing fans of fan page or friends of member\n\nPress 12 : for exit" << endl;
			getline(cin, c);
			choice = Isnt_number(c,1,12);
			if (choice >= 1 && choice <= 12)
				return choice;
			if (choice > 12 || choice < 1)
				throw ChoiceExp(1,12);
		}
		catch (NotANumberExp& e)
		{
			cin.clear();
			e.what();


		}
		catch (ChoiceExp& e)
		{
			e.what();
		}
	}



}
void Tasks(int choice, Facebook& face) noexcept(false)
{
	try
	{
		switch (choice)
		{
		case 1:
			AddMember(face);
			break;
		case 2:
			AddFanPage(face);
			break;
		case 3:
			AddStatus(face);
			break;
		case 4:
			Show_Statuss(face);
			break;
		case 5:
			Show_Statuss_Of_Friends(face);
			break;
		case 6:
			connectFriends(face);
			break;
		case 7:
			UnFriend(face);
			break;
		case 8:
			Add_A_Fan(face);
			break;
		case 9:
			Remove_A_Fan(face);
			break;
		case 10:
			face.ShowEm();
			break;
		case 11:
			Show_All_Friends_Fans(face);
			break;
		case 12:
			cout << "Thank you for using Facebook\nBye Bye\n";
			exit(1);
			break;
		default:
			throw ChoiceExp(1,12);
			break;
		}

		
	}
	catch (NotANumberExp& e)
	{
		
		e.what();


	}
	catch (ChoiceExp& e)
	{
		e.what();
	}
	catch (DateeExp& e)
	{
		e.what();
	}
	catch (MemberNameExp& e)
	{
		e.what();
	}
	catch (FanPageNameExp& e)
	{
		e.what();
		
	}
	catch (MemberFriendExp& e)
	{
		e.what();
		
	}
	catch (UserIsntInNetExp& e)
	{
		e.what();
	}
	catch (FanPageIsntInNetExp& e)
	{
		e.what();
	}
	
	catch (FaceBookExc& e)
	{
		e.what();
	}
	catch (...)
	{
		cout << "Eror ! Try again\n";
	}
}
int Isnt_number(string& c, int x, int y)
{
	for (int i = 0; i < c.size(); i++)
	{
		if (!isdigit(c[i]))
		{
			throw NotANumberExp(x, y);

		}
	}
	return(stoi(c));


}



//operators
//facebook obj operator

bool operator<(const Facebook_Obj& ob1, const Facebook_Obj& ob2)
{
	return(ob1.getNumOfFriends() < ob2.getNumOfFriends());
}
bool operator>(const Facebook_Obj& ob1, const Facebook_Obj& ob2)
{
	return(ob1.getNumOfFriends() > ob2.getNumOfFriends());
}
void operator+=(Facebook_Obj& ob1, Facebook_Obj& ob2)
{
	ob1.makeFriendship(&ob2);
}
bool operator==(Status& st1, Status& st2)
{
	string name1, name2;
	bool flag = false;
	VideoStatus *vid1, *vid2;
	ImageStatus *im1, *im2;
	name1 = typeid(st1).name();
	name2 = typeid(st2).name();

	if (name1.compare(name2) == 0)
	{
		if (st1.getStatus().compare(st2.getStatus()) != 0)
			return false;
			
	}
	
	

	vid1 = dynamic_cast<VideoStatus*>(&st1);
	if (vid1)
	{
		vid2= dynamic_cast<VideoStatus*>(&st2);

		name1 = vid1->getVideo();
		name2 = vid2->getVideo();
		if (name1.compare(name2) != 0)
			return false;
			
	}
	im1= dynamic_cast<ImageStatus*>(&st1);
	if (im1)
	{
		im2 = dynamic_cast<ImageStatus*>(&st2);

		name1 = im1->getImage();
		name2 = im2->getImage();
		if (name1.compare(name2) != 0)
			return false;

	}
	return true;

	

}

















//op1

//main fun 1
void AddMember(Facebook& face)
{
	string name;
	string year, month, day;
	int yearn, monthn, dayn;

	cout << "Enter name of a new member please : \n";
	getline(cin, name);
	face.isNameAvailableMem(name);
	cout << "Enter Year of birth   : \n";
	getline(cin, year);
	yearn = stoi(year);
	cout << "Enter Month of birth   : \n";
	getline(cin, month);
	monthn = stoi(month);
	cout << "Enter Day of birth   : \n";
	getline(cin, day);
	dayn = stoi(day);

	
	if (!checkdate(monthn, dayn,yearn))
	{
		throw DateeExp();
	}

	Member* mem = new Member(name, yearn, monthn, dayn);
	face.putMemInNet(mem);
}
	
bool checkdate(int m, int d, int y)
{
	
	if ((1900 >= y)||(y>2023))//comment these 2 lines out if it bothers you
		return false;
	if (!(1 <= m && m <= 12))
		return false;
	if (!(1 <= d && d <= 31))
		return false;
	if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
		return false;
	if ((d == 30) && (m == 2))
		return false;
	if ((m == 2) && (d == 29) && (y % 4 != 0))
		return false;
	if ((m == 2) && (d == 29) && (y % 400 == 0))
		return true;
	if ((m == 2) && (d == 29) && (y % 100 == 0))
		return false;
	if ((m == 2) && (d == 29) && (y % 4 == 0))
		return true;

	return true;
}


//main fun 2
void AddFanPage(Facebook& face)
{
	string name;


	cout << "Enter the name of the new fan page: \n";
	getline(cin, name);
	face.isNameAvailableFan(name);
	FanPage* f = new FanPage(name);
	face.putFanPageInNet(f);

	
	
		

}


//main fun 3
void AddStatus(Facebook& face)
{
	Status* newStat;
	ImageStatus* newStat2;
	VideoStatus* newStat1;
	string userName;
	string status;
	string c;
	string path;
	int x;
	int c1;
	cout << "Press 1: For adding a status for member\n\nPress 2: For adding status for a fan page\n";
	getline(cin, c);
	x = Isnt_number(c, 1, 2);
	switch (x)
	{
	case 1:
		cout << "Enter name of friend\n";
		getline(cin, userName);
		face.isNameNotAvailableMem(userName);
		break;
	case 2:
		cout << "Enter name of fan page:\n";
		getline(cin, userName);
		face.isNameNotAvailableFan(userName);
		break;
	default:
		throw ChoiceExp(1, 2);
		break;
			
	}

	cout << "Press 1: For adding a text status\n\nPress 2: For adding image status\n\nPress 3: For adding video status\n";
	getline(cin, c);
	c1 = Isnt_number(c, 1, 3);
	switch (c1)
	{
	case 1:
		cout << "Enter your status:\n";
		getline(cin, status);
		newStat = new Status(status);
		face.AddStatus(userName, newStat, x);
		break;
	case 2:
		cout << "Enter your status:\n";
		getline(cin, status);
		cout << "Enter path to Image file:\n";
		getline(cin, path);
		newStat2 = new ImageStatus(status, path);
		face.AddStatus(userName, newStat2, x);
		break;
	case 3:
		cout << "Enter your status:\n";
		getline(cin, status);
		cout << "Enter path to Video file:\n";
		getline(cin, path);
		newStat1 = new VideoStatus(status, path);
		face.AddStatus(userName, newStat1, x);
		break;
	default:
		throw ChoiceExp(1, 3);
		break;
	}
	

}
//main func 4
void Show_Statuss(Facebook& face)
{
	string c;
	int w;
	string Name;
	cout << "Press 1: For showing whole member status's\n\nPress 2: For showing whole fan page status's:\n";
	getline(cin, c);
	w = Isnt_number(c, 1, 2);;

	switch (w)
	{
	case 1:

		cout << "Enter name of friend\n";
		getline(cin, Name);
		face.isNameNotAvailableMem(Name);
		face.printLastTen(Name, w);
		break;
	case 2:
		cout << "Enter name of fan page:\n";
		getline(cin, Name);
		face.isNameNotAvailableFan(Name);
		face.printLastTen(Name, w);
		break;
	default:
		throw ChoiceExp(1, 2);

	}

}
//main func 5
void Show_Statuss_Of_Friends(Facebook& face)
{
	string friendName;
	cout << "Enter name of friend\n";
	getline(cin, friendName);
	face.isNameNotAvailableMem(friendName);
	face.showMostUpdated(friendName);
}
//main fun 6
void connectFriends(Facebook& face)
{
	string friend1;
	string friend2;

	cout << "\nEnter name of first friend\n";
	getline(cin, friend1);
	face.isNameNotAvailableMem(friend1);
	cout << "Enter name of second friend\n";
	getline(cin, friend2);
	face.isNameNotAvailableMem(friend2);
	if (friend1.compare(friend2) == 0)
	{
		throw MemberFriendExp();
	}
	else
	{
		face.connectThem(friend1, friend2);

	}
	
	


}
//main func 7
void UnFriend(Facebook& face)
{
	string friend1;
	string friend2;

	cout << "\nEnter name of first friend\n";
	getline(cin, friend1);
	face.isNameNotAvailableMem(friend1);
	cout << "Enter name of second friend\n";
	getline(cin, friend2);
	face.isNameNotAvailableMem(friend2);
	face.unFriend(friend1, friend2);
}
//main func 8
void Add_A_Fan(Facebook& face)
{
	string friendName1;
	string fanpage_name1;
	cout << "Enter name of friend\n";
	getline(cin, friendName1);
	face.isNameNotAvailableMem(friendName1);
	cout << "Enter name of fan page\n";
	getline(cin, fanpage_name1);
	face.isNameNotAvailableFan(fanpage_name1);

	face.Add_Fan(friendName1, fanpage_name1);


}
//main func 9
void Remove_A_Fan(Facebook& face)
{
	string friendName1;
	string fanpage_name1;
	cout << "Enter name of friend\n";
	getline(cin, friendName1);
	face.isNameNotAvailableMem(friendName1);
	cout << "Enter name of fan page\n";
	getline(cin, fanpage_name1);
	face.isNameNotAvailableFan(fanpage_name1);
	face.Delete_fan(friendName1, fanpage_name1);

}
//main func 11
void Show_All_Friends_Fans(Facebook& face)
{
	string name;
	string c;
	int w;
	cout << "Press 1 : for a member\n\nPress 2 : for a fan page\n";
	getline(cin, c);
	w = Isnt_number(c,1,2);;
	
	switch (w)
	{
	case 1:
		cout << "Enter Member name please\n";
		getline(cin, name);
		face.isNameNotAvailableMem(name);
		face.showHisFriend(w, name);
		break;
	case 2:
		cout << "Enter fan page name please\n";
		getline(cin, name);
		face.isNameNotAvailableFan(name);
		face.showHisFriend(w, name);
		break;
	default:
		throw ChoiceExp(1,2);
		break;





	}
}





