#pragma once
#include "vouchers.h"
//создание класса user
class User
{
public:
	void Obs_list(NODE* top);
	void searchByType(NODE* top);
	void searchByNutrition(NODE* top);
	void SortByDays(NODE*& top);
	void SortByCost(NODE*& top);
	void showAll(NODE*& top);
};