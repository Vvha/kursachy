#pragma once
#include "train.h"
//�������� ������ user
class User
{
public:
	void Obs_list(NODE* top);
	void searchByNum(NODE* top);
	void searchByDest(NODE* top);
	void SortByDate(NODE*& top);
	void BuyTicket(NODE*& top);
	void showRange(NODE* top);
};