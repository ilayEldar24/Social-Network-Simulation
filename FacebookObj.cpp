#include "FacebookObj.h"
Facebook_Obj::Facebook_Obj(const string& name) :Name(name) {};
const string Facebook_Obj:: getName()const
{
	return Name;
}
void Facebook_Obj::setStatus(Status* status)
{

	feed.AddStatus(status);

}
void Facebook_Obj::ShowTenStatuss() const
{
	cout << "\nLast status's of " << Name << "\n";
	feed.showLastTen();
}
bool Facebook_Obj::isNotFriend(Facebook_Obj* other) const
{
	int i;
	
	
	
		for (i = 0; i < this->units.size(); i++)
		{
			if (this->units[i]->getName() == other->getName())
			{
				if((typeid(other).name())==(typeid(units[i]).name()))
					return false;


			}
		}
		return true;

		
}
void Facebook_Obj::ShowFriends()const
{
	for (int i = 0; i < units.size(); i++)
	{
		
		
		cout << "User number " << i + 1 << " : " << units[i]->getName() << "\n";

		
	 
	}
	
}
 int Facebook_Obj::getNumOfFriends()const
{
	 return (units.size());

}
 void Facebook_Obj:: makeFriendship(Facebook_Obj* other)
 {
	 if (this->isNotFriend(other))
	 {
		 units.push_back(other);
		 other->makeFriendship(this);
	 }


}
 void Facebook_Obj::deleteFriend(Facebook_Obj* other)
 {
	 if (!this->isNotFriend(other))
	 {
		 for (int i = 0; i < units.size(); i++)
		 {
			 if (other->getName().compare(units[i]->getName()) == 0)
			 {
				 if (typeid(other) == typeid(units[i]))
				 {
					 units[i] = units[units.size() - 1];
					 units.pop_back();

				 }
					 

			 }
		 }
		 other->deleteFriend(this);
	 }
 }
