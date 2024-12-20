#include "facebook.h"

Facebook::~Facebook()
{
	for (int i = 0; i < users.size(); i++)
	{
		delete users[i];
	}

	
}


//Q1 FUNCTIONS:

void Facebook::putMemInNet(Member* mem)
{
	users.push_back(mem);
	
	
}

//Q2 FUNCTIONS:

void Facebook::putFanPageInNet(FanPage* f)
{
	users.push_back(f);
	

}
const Facebook& Facebook::operator+=(FanPage* f)
{
	this->putFanPageInNet(f);
	return *this;
}

//Q3 FUNCTIONS:
void Facebook::AddStatus(const string& name, Status* status,int& cho)
{
	if (cho == 1)
	{
		
		for (int i = 0; i < users.size(); i++)
		{
			if (name.compare(users[i]->getName()) == 0)
			{
				Member* temp = dynamic_cast <Member*>(users[i]);
				if (temp)
				{
					users[i]->setStatus(status);
					break;

				}

				
			}
		}

	}
	else
	{
		
		for (int i = 0; i < users.size(); i++)
		{
			if (name.compare(users[i]->getName()) == 0)
			{
				FanPage* temp = dynamic_cast <FanPage*>(users[i]);
				if (temp)
				{
					users[i]->setStatus(status);
					break;

				}
			}
		}

	}
	


}

//Q4 FUCTIONS:
void Facebook::printLastTen(const string& name,int& cho)const
{
	if (cho == 1)
	{

		for (int i = 0; i < users.size(); i++)
		{
			if (name.compare(users[i]->getName()) == 0)
			{
				Member* temp = dynamic_cast <Member*>(users[i]);
				if (temp)
				{
					users[i]->ShowTenStatuss();
					break;

				}


			}
		}

	}
	else
	{

		for (int i = 0; i < users.size(); i++)
		{
			if (name.compare(users[i]->getName()) == 0)
			{
				FanPage* temp = dynamic_cast <FanPage*>(users[i]);
				if (temp)
				{
					users[i]->ShowTenStatuss();
					break;

				}
			}
		}

	}

}


//Q5 FUNCTIONS:
void Facebook::showMostUpdated(const string& name)const
{

	bool flag = false;
	for (int i = 0; i < users.size(); i++)
	{
		if (name.compare(users[i]->getName()) == 0)
		{
			Member* temp = dynamic_cast<Member*>(users[i]);
			if (temp)
			{
				temp->showTenUpdated();
				break;

			}
		}
	}
	

}

//Q6 FUNC
void Facebook::connectThem(const string& name1, const string& name2)
{
		Member* mem1 = nullptr, * mem2 = nullptr;
		int i;
		for (i = 0; i < users.size(); i++)
		{
			if (name1.compare(users[i]->getName()) == 0)
			{
				mem1 = dynamic_cast<Member*>(users[i]);
				if (mem1)
				{
					break;
				}
				
			}
		}


		for (i = 0; i < users.size(); i++)
		{
			if (name2.compare(users[i]->getName()) == 0)
			{
				mem2 = dynamic_cast<Member*>(users[i]);
				if (mem2)
				{
					break;
				}
			}
		}
		mem1->makeFriendship(mem2);
		
		
		

}

//Q7 FUNC
//Q7 FUNC
void Facebook::unFriend(const string& name1, const string& name2)
{
	Member* mem1, * mem2;
	mem1 = mem2 = nullptr;
	int i;
	for (i = 0; i < users.size(); i++)
	{
		if (name1.compare(users[i]->getName()) == 0)
		{
			Member* Mem1 = dynamic_cast<Member*>(users[i]);
			if (Mem1)
			{
				break;
			}
		}
	}
	for (i = 0; i < users.size(); i++)
	{
		if (name2.compare(users[i]->getName()) == 0)
		{
			Member* Mem2 = dynamic_cast<Member*>(users[i]);
			if (Mem2)
			{
				break;
			}
		}
	}
	mem1->deleteFriend(mem2);
}
//Q8 FUNC
void Facebook::Add_Fan(const string& friend_name, const string& fanpage_name)
{
	Member* mem1 = nullptr;
	FanPage* fan1 = nullptr;
	int i;
	for (i = 0; i < users.size(); i++)
	{
		if (friend_name.compare(users[i]->getName()) == 0)
		{
			mem1 = dynamic_cast<Member*>(users[i]);
			if (mem1)
			{
				break;
			}
		}
	}
	for (i = 0; i < users.size(); i++)
	{
		if (fanpage_name.compare(users[i]->getName()) == 0)
		{
			fan1 = dynamic_cast<FanPage*>(users[i]);
			if (fan1)
			{
				break;
			}
		}
	}
	mem1->makeFriendship(fan1);
}

//Q9 FUNC
void Facebook::Delete_fan(const string& friend_name, const string& fanPageName)
{
	Member* mem = nullptr;
	FanPage* page = nullptr;
	for (int i = 0; i < users.size(); i++)
	{
		if (friend_name.compare(users[i]->getName()) == 0)
		{
			mem = dynamic_cast<Member*>(users[i]);
			if (mem)
			{
				break;
			}
		}
	}
	for (int i = 0; i < users.size(); i++)
	{
		if (fanPageName.compare(users[i]->getName()) == 0)
		{
			page = dynamic_cast<FanPage*>(users[i]);
			if (page)
			{
				break;
			}
		}
	}
	page->deleteFriend(mem);
}

//Q10 FUNC
void Facebook::ShowEm()const
{
	int i;
	Member* mem = nullptr;
	FanPage* fan = nullptr;

	cout << "All of the members are : \n";
	for (i = 0; i < users.size(); i++)
	{
		mem = dynamic_cast<Member*>(users[i]);
		if (mem)
		{
			cout << users[i]->getName() << "\n";
			mem = nullptr;

		}
		
	}
	cout << "All of the fan pages are : \n";
	for (i = 0; i < users.size(); i++)
	{
		fan = dynamic_cast<FanPage*>(users[i]);
		if (fan)
		{
			cout << users[i]->getName() << "\n";
			fan = nullptr;

		}
	}
}

//Q11 FUNC
void Facebook::showHisFriend(int& cho, const string& name)const
{
		int i;
		Member* mem = nullptr;
		FanPage* page = nullptr;
		bool flag = false;
		switch (cho)
		{
		case 1:

			for (i = 0; i < users.size(); i++)
			{
				if (name.compare(users[i]->getName()) == 0)
				{
					mem = dynamic_cast<Member*>(users[i]);
					if (mem)
					{
						mem->ShowFriends();
						break;
					}
					
				}
			}
			
			break;
		case 2:

			for (i = 0; (i < users.size()) && (!flag); i++)
			{
				if (name.compare(users[i]->getName()) == 0)
				{
					page = dynamic_cast<FanPage*>(users[i]);
					if (page)
					{
						page->ShowFans();
						break;
					}
					
				}

			}
			break;
			
			
		}


		
		
			

		

}


//excptions func
void Facebook::isNameAvailableMem(string str) noexcept(false)
{
	int i = 0;
	for (i = 0; i < users.size(); i++)
	{
		if (users[i]->getName().compare(str) == 0) // execption
		{
			Member* temp = dynamic_cast<Member*>(users[i]);
			if (temp)
			{
				throw MemberNameExp(str);
			}
		}
	}
}
void Facebook::isNameNotAvailableMem(string str) noexcept(false)
{
	int i = 0;
	bool found = false;
	for (i = 0; i < users.size(); i++)
	{
		if (users[i]->getName().compare(str) == 0) // execption
		{
			Member* tmp = dynamic_cast<Member*>(users[i]);
			if (tmp)
			{
				found = true;
				break;
			}
		}
	}
	if (found == false)
	{
		throw UserIsntInNetExp(str);
	}
}
void Facebook::isNameAvailableFan(string str)
{
	int i = 0;
	for (i = 0; i < users.size(); i++)
	{
		if (users[i]->getName().compare(str) == 0) // execption
		{
			FanPage* tmp = dynamic_cast<FanPage*>(users[i]);
			if (tmp)
			{
				throw FanPageNameExp(str);
			}
		}
	}
}
void Facebook::isNameNotAvailableFan(string str)
{
	int i = 0;
	bool found = false;
	for (i = 0; i < users.size(); i++)
	{
		if (users[i]->getName().compare(str) == 0) // execption
		{
			FanPage* tmp = dynamic_cast<FanPage*>(users[i]);
			if (tmp)
			{
				found = true;
			}
		}
	}
	if (found == false)
	{
		throw FanPageIsntInNetExp(str);
	}
}