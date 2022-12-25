#include "train.h"

int DATA::total = 0;
NODE* NODE::head = nullptr;
// ���������� ������������
DATA::DATA(int tr_num, string dest_place, int datedep, int timedep, int timearr, int tick_cost, int tick_left, int tick_sold)
	: id(total++) // ���������������
{
	this->tr_num = tr_num;
	this->dest_place = dest_place;
	this->datedep = datedep;
	this->timedep = timedep;
	this->timearr = timearr;
	this->tick_cost = tick_cost;
	this->tick_left = tick_left;
	this->tick_sold = tick_sold;
}
// ����������� � ����� �����������
NODE::NODE(DATA data, NODE* next) : data(data), next(next) {}
// ���������� ������������
NODE::NODE(int tr_num, string dest_place, int datedep, int timedep, int timearr, int tick_cost, int tick_left, int tick_sold, NODE* next)
	: next(next), data(tr_num, dest_place, datedep, timedep, timearr, tick_cost, tick_left, tick_sold) {}
// ����������
NODE::~NODE() {	data.total--; }

// ������ � ������ next
NODE* NODE::GetNext() { return next; }
void NODE::SetNext(NODE* ptr) { next = ptr; }
// ������ � ������ head
NODE* NODE::GetHead() { return head; }
void NODE::SetHead(NODE* ptr) { head = ptr; }
/* ���������� ������� */
bool empty(NODE* node) 
{
	if (!node) {
		cout << "������ ����!";
		return true;
	}
	return false;
}
// ���������� ������� ����������
// ���������� ���� � ������ ������
void push(NODE*& head, DATA new_data)
{
	NODE* p = new NODE(new_data);
	p->SetNext(head);
	NODE::SetHead(p);
}
// ���������� ���� ����� ������� ����
void insertAfter(NODE*& prev_node, DATA new_data)
{
	NODE* p = new NODE(new_data);
	p->SetNext(prev_node->GetNext());
	prev_node->SetNext(p);
}
// ���������� ���� � ����� ������
void append(NODE*& head, DATA new_data)
{
	NODE* p = head;
	while (p->GetNext()) {
		p = p->GetNext();
	}
	insertAfter(p, new_data);
}
// �������� �� ������
void pop_head(NODE*& head)
{
	if (!head) { return; }
	NODE* temp = head;
	head = head->GetNext();
	delete temp;
}
// �������� ����� ����
void pop_after(NODE*& prev_node)
{
	NODE* temp = prev_node->GetNext();
	prev_node->SetNext(temp->GetNext());
	delete temp;
}
// ����� �� ������ ������
NODE* find(NODE*& head, int tr_num)
{
	NODE* p = head;
	while (p) {
		if (p->data.tr_num == tr_num) break;
		p = p->GetNext();
	}
	return p;
}
// ����� �� ����������� ������
NODE* findById(NODE* head, int id)
{
	NODE* p = head;
	while(p->data.id  != id && p) {
		p = p->GetNext();
	}
	return p;
}

// �������� ������ �� �����
void download(NODE*& head, ifstream& fin)
{
	head = new NODE;
	string line;
	size_t pos;
	while (getline(fin, line)) {
		DATA data;
		int c = 0;
		while ((pos = line.find(" ")) != string::npos || pos + 1 != line.length()) {
			string subs = line.substr(0, pos);
			switch (c) {
			case 0:
				data.tr_num = stoi(subs);
				break;
			case 1:
				data.dest_place = subs;
				break;
			case 2:
				data.datedep = ConvertStD(subs);
				break;
			case 3:
				data.timedep = ConvertStT(subs);
				break;
			case 4:
				data.timearr = ConvertStT(subs);
				break;
			case 5:
				data.tick_cost = stoi(subs);
				break;
			case 6:
				data.tick_left = stoi(subs);
				break;
			case 7:
				data.tick_sold = stoi(subs);
				break;
			default:
				break;
			}
			if (c == 7)
				break;
			else
				line.erase(0, pos + 1);
			c++;
		}
		append(head, data);
	}
	pop_head(head);
	reset(head);
}
// ����� ����� ����
void show(NODE*& node)
{
	if (empty(node)) return;
	printf(" %-3i | %-11s | %-5s | %-5s | %-5s | %-5i | %-3i | %-3i\n", node->data.tr_num, node->data.dest_place.c_str(), ConvertDtS(node->data.datedep).c_str(), ConvertTtS(node->data.timedep).c_str(), ConvertTtS(node->data.timearr).c_str(), node->data.tick_cost, node->data.tick_left, node->data.tick_sold);
}
// ����� ����� ������
void obs_list(NODE* head)
{
	for (NODE* p = head; p; p = p->GetNext()) {
		show(p);
	}
}
// ���������� ���� id
void reset(NODE*& head)
{
	NODE* p = head;
	int c=0;
	while (p) {
		c++;
		p->data.id = c;
		p = p->GetNext();
	}
}

// �������������� ������� � ����
int ConvertStD(string date) {
	return stoi(date.substr(0, 2)) + stoi(date.substr(3, 2)) * 30;
}

int ConvertStT(string time)
{
	return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

string ConvertDtS(int date) {
	return to_string(date % 30) + "." + to_string(date / 30);
}

string ConvertTtS(int time)
{
	return to_string(time / 60) + ":" + to_string(time % 60);
}