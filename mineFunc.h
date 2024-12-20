
#ifndef MINEFUNC_H
#define MINEFUNC_H
#include <iostream>
#define CRT_SECURE_NO_WAARRINGS
#include <string.h>
#include "Member.h"
#include "FanPage.h"
#include "facebook.h"
#include "SystemExc.h"
#include "FacebookObj.h"


class Facebook;

int printmenu();
void Tasks(int choice, Facebook& face)noexcept(false);
int Isnt_number(string& c, int x, int y);


//op 1 func
void AddMember(Facebook& face)noexcept(false);
bool checkdate(int m, int d, int y);
void AddFanPage(Facebook& face);
void connectFriends(Facebook& face);

//func 3
void AddStatus(Facebook& face);

//func 4
void Show_Statuss(Facebook& face);
//main func 5
void Show_Statuss_Of_Friends(Facebook& face);
//main fun 6
void connectFriends(Facebook& face);

//main func 7
void UnFriend(Facebook& face);
//main func 8
void Add_A_Fan(Facebook& face);
//main func 9
void Remove_A_Fan(Facebook& face);
//main func 11
void Show_All_Friends_Fans(Facebook& face);

#endif