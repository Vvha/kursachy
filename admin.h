#pragma once
#include "vouchers.h"

class Admin
{
public:
	void Obs_list(NODE* top);
	void Add(NODE*& top);
	void Del(NODE*& top, int id);
	void Edit(NODE*& top, int id);
};