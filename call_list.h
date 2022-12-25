#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// класс для хранения данных
class DATA
{
public:
	// объявление полей (дата, время, длительность)
	int call_date, call_time, callduration;
	//адресант, фамилия, тип, адресат
	string number, surname, calltype, call_number; 
	int id;
	static int count;
	// объявление конструктора
	DATA(string number = "", string surname = "", string calltype = "", string call_number = "", int call_date = 0, int call_time = 0, int callduration = 0);
	friend class NODE;
};


class NODE
{
public:
	NODE* next;
	static NODE* head;
	DATA data;
	// объявление конструкторов и дестркукторов
	NODE(DATA data, NODE* next);
	
	NODE(string number, string surname, string calltype, string call_number, int call_date, int call_time, int callduration, NODE* next);
	~NODE();
};
// объявление методов
// добаление узлов в список
void push(NODE*& head, DATA new_data);
void insertAfter(NODE*& prev_node, DATA new_data);
void append(NODE*& head, DATA new_data);
// удаление узлов из списка
void pop_head(NODE*& head);
void pop_after(NODE*& ptr);
// поиск по списку
NODE* find(NODE*& head, int id);
// работа со списком
void download(NODE*& head, ifstream& fin);
void show(NODE*& node);
void obs_list(NODE* head);
void reset(NODE* head);
// методы преобразования дат и времени
int ConvertStD(string date);
int ConvertStT(string time);
string ConvertDtS(int date);
string ConvertTtS(int time);