#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// ����� ��� �������� ������
class DATA
{
public:
	// ����� ������, ���� � ����� �����������, ����� ��������, ���� ������, ������� �������, ���-�� ���������
	int tr_num, datedep, timedep, timearr, tick_cost, tick_left, tick_sold;
	string dest_place; // ����� ����������
	int id;
	static int total;
	// ���������� ������������
	DATA(int tr_num = 0, string dest_place = "", int datedep = 0, int timedep = 0, int timearr = 0, int tick_cost = 0, int tick_left = 0, int tick_sold = 0);
	friend class NODE;
};


class NODE
{
public:
	// ���������� ������������� � �������������
	NODE(DATA data, NODE* next = nullptr);
	
	NODE(int tr_num = 0, string dest_place = "", int datedep = 0, int timedep = 0, int timearr = 0, int tick_cost = 0, int tick_left = 0, int tick_sold = 0, NODE* next = nullptr);
	~NODE();
	// ������ ������ �� ����. ������� ������
	NODE* GetNext();
	// ������ ������ �� ����. ������� ������
	void SetNext(NODE* ptr);
	// ������ �������� �������� ������
	static NODE* GetHead();
	// ������ �������� �������� ������
	static void SetHead(NODE* ptr);
	DATA data;
private:
	NODE* next;
	static NODE* head;
};
// ���������� �������
bool empty(NODE* node);
// ��������� ����� � ������
void push(NODE*& head, DATA new_data);
void insertAfter(NODE*& prev_node, DATA new_data);
void append(NODE*& head, DATA new_data);
// �������� ����� �� ������
void pop_head(NODE*& head);
void pop_after(NODE*& ptr);
// ����� �� ������
NODE* find(NODE*& head, int tr_num);
NODE* findById(NODE* head, int id);
// ������ �� �������
void download(NODE*& head, ifstream& fin);
void show(NODE*& node);
void obs_list(NODE* head);
void reset(NODE*& head);
// ������ �������������� ��� � �������
int ConvertStD(string date);
int ConvertStT(string time);
string ConvertDtS(int date);
string ConvertTtS(int time);