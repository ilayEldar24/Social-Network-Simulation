#include "Feed.h"

Feed::~Feed()
{
	int i;
	for (i = 0; i < arrOfStatuses.size(); i++)
		delete arrOfStatuses[i];

}
void Feed::AddStatus(Status* newStat)
{
	arrOfStatuses.push_back(newStat);

}
void Feed::showLastTen() const
{
	ImageStatus* img = nullptr;
	VideoStatus* vid = nullptr;
	if (arrOfStatuses.empty())
	{
		cout << "No status's for shown\n";
	}
	else
	{
		
		for (int i=0;i< arrOfStatuses.size();i++)
		{
			img = dynamic_cast<ImageStatus*>(arrOfStatuses[i]);
			if (img)
			{
				cout << "Status Num " << i << " : \n" << " Type of status : Image Status :";
				img->printStatus();
				img = nullptr;
			}
			else
			{
				vid= dynamic_cast<VideoStatus*>(arrOfStatuses[i]);
				if (vid)
				{
					cout << "Status Num " << i << " : \n" << " Type of status : Video Status :";
					vid->printStatus();
					vid = nullptr;

				}
				else
				{
					cout << "Status Num " << i << " : \n" << " Type of status : Text Status :";
					arrOfStatuses[i]->printStatus();
					

				}
			}
			
			
		}
	}
}