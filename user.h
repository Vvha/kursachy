#pragma once
#include "call_list.h"
//�������� ������ user
class User
{
public:
	void Obs_list(NODE* top);
	void searchByName(NODE* top);
	void searchByNumber(NODE* top);
	void SortByDate(NODE*& top);
	void SortByDuration(NODE*& top);
	void SortBySurname(NODE*& top);
	void outCalls(NODE* top);
};