#include "vouchers.h"

int DATA::count = 0;
NODE* NODE::head = nullptr;
// реализация конструктора DATA
DATA::DATA(string vouch_type, int days_amount, string nutrition, int cost)
	: id(++count) 
{
	this->vouch_type = vouch_type;
	this->days_amount = days_amount;
	this->nutrition = nutrition;
	this->cost = cost;
}

// конструктор NODE с двумя аргументами
NODE::NODE(DATA data, NODE* next = nullptr) : data(data), next(next) {}
// перегрузка конструктора
NODE::NODE(string vouch_type, int days_amount, string nutrition, int cost, NODE* next)
	: data(vouch_type, days_amount, nutrition, cost), next(next) {}
// деструктор
NODE::~NODE() {	data.count--; }

/* Описание функций и процедур */

// Описание функций добавления

// добавление узла в начало списка
void push(NODE*& head, DATA new_data)
{
	NODE* p = new NODE(new_data);
	p->next = head;
	head = p;
}
// добавление узла после другого узла
void insertAfter(NODE*& prev_node, DATA new_data)
{
	NODE* p = new NODE(new_data);
	p->next = prev_node->next;
	prev_node->next = p;
}
// добавление узла в конец списка
void append(NODE*& head, DATA new_data)
{
	NODE* p = head;
	while (p->next) {
		p = p->next;
	}
	insertAfter(p, new_data);
}
// удаление из головы
void pop_head(NODE*& head)
{
	if (!head) { return; }
	NODE* temp = head;
	head = head->next;
	delete temp;
}
// удаление после узла
void pop_after(NODE*& prev_node)
{
	NODE* temp = prev_node->next;
	prev_node->next = temp->next;
	delete temp;
}
// поиск по порядковому номеру
NODE* find(NODE*& head, int id)
{
	NODE* p = head;
	while (p) {
		if (p->data.id == id) break;
		p = p->next;
	}
	return p;
}

// загрузка списка из файла
void ReadFile(NODE*& head, ifstream& fin)
{
	head = new NODE; // инициализация опроного узла
	string line;
	string separator = ";";
	while (getline(fin, line)) {
		DATA data;
		size_t pos;
		int c = 0;
		while ((pos = line.find(separator)) != string::npos || pos + 1 != line.length()) {
			string subs = line.substr(0, pos);
			c++;
			switch (c) {
			case 1:
				data.vouch_type = subs;
				break;
			case 2:
				data.days_amount = stoi(subs);
				break;
			case 3:
				data.nutrition = subs;
				break;
			case 4:
				data.cost = stoi(subs);
				break;
			default:
				break;
			}
			if (c == 4)
				break;
			else
				line.erase(0, pos + separator.length());
		}
		append(head, data);// добаление нового элемента в конец списка (для создания очереди)
	}
	pop_head(head); // так как добавление данных в список закончилось, то опорный узел отпадает по ненадобности (удаление из головы)
	reset(head);
}
// вывод полей узла
void show(NODE*& node)
{
	if (!node) return; // если node == nullptr, то выход из процедуры
	printf(" %-3i | %-7s | %-2i | %-13s | %-6i\n", node->data.id, node->data.vouch_type.c_str(), node->data.days_amount, node->data.nutrition.c_str(), node->data.cost);
}
// вывод всего списка
void obs_list(NODE* head)
{
	for (NODE* p = head; p; p = p->next) {
		show(p);
	}
}
// обновление поля id (каждый раз при удалении узла или сортировке списка)
void reset(NODE*& head)
{
	NODE* p = head;
	int c=0;
	while (p) {
		c++;
		p->data.id = c;
		p = p->next;
	}
}

// преобразование времени и даты
int ConvertStD(string date) {
	return stoi(date.substr(0, 2)) * 30 + stoi(date.substr(3, 2));
}

int ConvertStT(string time)
{
	return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

string ConvertDtS(int date) {
	string str = "";
	if (date / 30 < 10) str = "0";
	str += to_string(date / 30) +".";
	if (date % 30 < 10) str += "0";
	str += to_string(date % 30);
	return str;
}

string ConvertTtS(int time)
{
	string str = "";
	if (time / 60 < 10) str += "0";
	str += to_string(time / 60) + ":";
	if (time % 60 < 10) str += "0";
	str += to_string(time % 60);
	return str;
}                                        