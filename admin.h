#pragma once
#include "call_list.h"

class Admin
{
public:
	void Obs_list(NODE* top);
	void Add(NODE*& top);
	void Del(NODE*& top, int id);
	void Edit(NODE*& top, int id);
};