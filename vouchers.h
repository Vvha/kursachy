#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// ��������� ��� �������� ������
struct DATA
{
	//���������� �����
	string vouch_type, nutrition;
	int days_amount, cost;
	static int count;
	int id;
	//�����������
	DATA(string vouch_type = "", int days_amount = 0, string nutrition = "", int cost = 0);
};

// ��������� ����
struct NODE
{
	// ���������� �����
	NODE* next;// ��������� �� �������� ���� � ������
	static NODE* head; // ����������� ��������� �� ������� ����
	DATA data; // ��������� data ��� �������� ������
	// ���������� ������������� � �������������
	NODE(DATA data, NODE* next);
	
	NODE(string vouch_type = "", int days_amount = 0, string nutrition = "", int cost = 0, NODE* next = nullptr);
	~NODE();
};
// ���������� �������
// ��������� ����� � ������
void push(NODE*& head, DATA new_data);
void insertAfter(NODE*& prev_node, DATA new_data);
void append(NODE*& head, DATA new_data);
// �������� ����� �� ������
void pop_head(NODE*& head);
void pop_after(NODE*& ptr);
// ����� �� ������
NODE* find(NODE*& head, int id);
// ������ �� �������
void ReadFile(NODE*& head, ifstream& fin);
void show(NODE*& node);
void obs_list(NODE* head);
void reset(NODE*& head);
// ������ �������������� ��� � �������
int ConvertStD(string date);
int ConvertStT(string time);
string ConvertDtS(int date);
string ConvertTtS(int time);