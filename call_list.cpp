#include "call_list.h"

int DATA::count = 0;
NODE* NODE::head = nullptr;
// реализация конструктора
DATA::DATA(string number, string surname, string calltype, string call_number, int call_date, int call_time, int callduration) : id(count++)
{
	this->number = number;
	this->surname = surname;
	this->calltype = calltype;
	this->call_number = call_number;
	this->call_date = call_date;
	this->call_time = call_time;
	this->callduration = callduration;
}

// конструктор с двумя аргументами
NODE::NODE(DATA data, NODE* next = nullptr) : data(data), next(next) {}
// перегрузка конструктора
NODE::NODE(string number = "", string surname = "", string calltype = "", string call_number = "", int call_date = 0, int call_time = 0, int callduration = 0, NODE* next = nullptr)
	: next(next), data(number, surname, calltype, call_number, call_date, call_time, callduration) {}
// деструктор
NODE::~NODE() {	data.count--; }

/* Реализаиця методов */

// реализация методов добавления

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
void download(NODE*& head, ifstream& fin)
{
	head = new NODE; // инициализация опроного узла
	string line;
	size_t pos;
	while (getline(fin, line)) {
		DATA data;
		int c = 0;
		while ((pos = line.find(" ")) != string::npos || pos + 1 != line.length()) {
			string subs = line.substr(0, pos);
			switch (c) {
			case 0:
				data.number = subs;
				break;
			case 1:
				data.surname = subs;
				break;
			case 2:
				data.calltype = subs;
				break;
			case 3:
				data.call_number = subs;
				break;
			case 4:
				data.call_date = ConvertStD(subs);
				break;
			case 5:
				data.call_time = ConvertStT(subs);
				break;
			case 6:
				data.callduration= ConvertStT(subs);
				break;
			default:
				break;
			}
			if (c == 6)
				break;
			else
				line.erase(0, pos + 1);
			c++;
		}
		append(head, data);// добаление нового элемента в конец списка (для создания очереди)
	}
	pop_head(head); // так как добавление данных в список закончилось, то опорный узел отпадает по ненадобности (удаление из головы)
}
// вывод полей узла
void show(NODE*& node)
{
	if (!node) return; // если node == nullptr, то выход из процедуры
	printf(" %-3i | %-12s | %-12s | %-9s | %-12s | %-5s | %-5s | %-5s\n", node->data.id, node->data.number.c_str(),node->data.surname.c_str(), node->data.calltype.c_str(), node->data.call_number.c_str(), ConvertDtS(node->data.call_date).c_str(), ConvertTtS(node->data.call_time).c_str(), ConvertTtS(node->data.callduration).c_str());
}
// вывод всего списка
void obs_list(NODE* head)
{
	for (NODE* p = head; p; p = p->next) {
		show(p);
	}
}
// обновление поля id (каждый раз при удалении узла или сортировке списка)
void reset(NODE* head)
{
	NODE* p = head;
	int c=0;
	while (p) {
		c++;
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