#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// класс дл€ хранени€ данных
class DATA
{
public:
	// номер поезда, дата и врем€ отправлени€, врем€ прибыти€, цена билета, остаток билетов, кол-во проданных
	int tr_num, datedep, timedep, timearr, tick_cost, tick_left, tick_sold;
	string dest_place; // пункт назначени€
	int id;
	static int total;
	// объ€вление конструктора
	DATA(int tr_num = 0, string dest_place = "", int datedep = 0, int timedep = 0, int timearr = 0, int tick_cost = 0, int tick_left = 0, int tick_sold = 0);
	friend class NODE;
};


class NODE
{
public:
	// объ€вление конструкторов и дестркукторов
	NODE(DATA data, NODE* next = nullptr);
	
	NODE(int tr_num = 0, string dest_place = "", int datedep = 0, int timedep = 0, int timearr = 0, int tick_cost = 0, int tick_left = 0, int tick_sold = 0, NODE* next = nullptr);
	~NODE();
	// геттер ссылки на след. элемент списка
	NODE* GetNext();
	// сеттер ссылки на след. элемент списка
	void SetNext(NODE* ptr);
	// геттер верхнего элемента списка
	static NODE* GetHead();
	// сеттер верхнего элемента списка
	static void SetHead(NODE* ptr);
	DATA data;
private:
	NODE* next;
	static NODE* head;
};
// объ€вление методов
bool empty(NODE* node);
// добаление узлов в список
void push(NODE*& head, DATA new_data);
void insertAfter(NODE*& prev_node, DATA new_data);
void append(NODE*& head, DATA new_data);
// удаление узлов из списка
void pop_head(NODE*& head);
void pop_after(NODE*& ptr);
// поиск по списку
NODE* find(NODE*& head, int tr_num);
NODE* findById(NODE* head, int id);
// работа со списком
void download(NODE*& head, ifstream& fin);
void show(NODE*& node);
void obs_list(NODE* head);
void reset(NODE*& head);
// методы преобразовани€ дат и времени
int ConvertStD(string date);
int ConvertStT(string time);
string ConvertDtS(int date);
string ConvertTtS(int time);