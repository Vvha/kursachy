#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// структура для хранения данных
struct DATA
{
	//объявление полей
	string vouch_type, nutrition;
	int days_amount, cost;
	static int count;
	int id;
	//конструктор
	DATA(string vouch_type = "", int days_amount = 0, string nutrition = "", int cost = 0);
};

// структура узла
struct NODE
{
	// объявление полей
	NODE* next;// указатель на следующи узел в списке
	static NODE* head; // статический укзаатель на верхний узел
	DATA data; // структура data для хранения данных
	// объявление конструкторов и дестркукторов
	NODE(DATA data, NODE* next);
	
	NODE(string vouch_type = "", int days_amount = 0, string nutrition = "", int cost = 0, NODE* next = nullptr);
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
void ReadFile(NODE*& head, ifstream& fin);
void show(NODE*& node);
void obs_list(NODE* head);
void reset(NODE*& head);
// методы преобразования дат и времени
int ConvertStD(string date);
int ConvertStT(string time);
string ConvertDtS(int date);
string ConvertTtS(int time);