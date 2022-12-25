#include "user.h"
// ���������� �����
void User::Obs_list(NODE* top)
{
	obs_list(top);
}
// ����� �� ���� ������
void User::searchByType(NODE* top)
{
	cout << "1. �����\n2. �������\n";
	size_t c;
	string ss;
	do {
		cin >> c;
		if (c == 1) ss = "�����";
		else if (c == 2) ss = "�������";
		else cout << "������������ ����!\n";
	} while (c != 1 && c != 2);
	NODE* p = top;
	while (p) {
		// ���� ��������� �� ���� �������, � ����� ������ find() ����� -1 = npos
		if (p->data.vouch_type.find(ss) != string::npos) show(p);
		p = p->next;// ������� �� ���� �������
	}
}
// ����� ���� ����������, � ������� ���������� �������� �����
void User::searchByNutrition(NODE* top)
{
	int c;
	NODE* p = top;
	string ss;
	cout << "������� ��� �������:\n1. �������\n2. �� ��������\n";
	do {
		cin >> c;
		if (c == 1) ss = "�������";
		else if (c == 2) ss = "�� ��������";
		else cout << "�������� ����! ���������� �����\n";
	} while (c != 1 && c != 2);
	cout << ": ";
	cin >> ss;// ���� �������
	while (p) {
		// ���� ��������� �� ���� �������, � ����� ������ find() ����� -1 = npos
		// ����� ���������� �� ���� ����� ������� - �������� � ��������� ������
		if (p->data.nutrition.find(ss) != string::npos) show(p);
		p = p->next;
	}
}

// ���������� �� ����
void User::SortByDays(NODE*& top)
{
	if (!top) return;
	NODE* a, *b, *p, *h = NULL;

	for (NODE* i = top; i != NULL; ) {
		a = i;
		i = i->next;
		b = h;
		for (p = NULL; (b != NULL) && (a->data.days_amount < b->data.days_amount); ) {
			p = b;
			b = b->next;
		}
		if (p == NULL) {
			a->next = h;
			h = a;
		}
		else {
			a->next = b;
			p->next = a;
		}
	}
	if (h != NULL)
		top = h;
	reset(top);

}
// ���������� �� ���������
void User::SortByCost(NODE*& top)
{
	if (!top) return;
	NODE* a, * b, * p, * h = NULL;

	for (NODE* i = top; i != NULL; ) {
		a = i;
		i = i->next;
		b = h;
		for (p = NULL; (b != NULL) && (a->data.cost < b->data.cost); ) {
			p = b;
			b = b->next;
		}
		if (p == NULL) {
			a->next = h;
			h = a;
		}
		else {
			a->next = b;
			p->next = a;
		}
	}
	if (h != NULL)
		top = h;
	reset(top);

}

void User::showAll(NODE*& top)
{
	SortByCost(top);
	NODE* temp = top;
	int c;
	string str;
	cout << "1. �����\n2. �������\n";
	do {
		cin >> c;
		if (c == 1) str = "�����";
		else if (c == 2) str = "�������";
		else cout << "������������ ����!\n";
	} while (c != 1 && c != 2);
	cout << "������� ����: ";
	cin >> c;
	int counter =0;
	while (temp) {
		if (temp->data.cost < c && temp->data.vouch_type == str) {
			counter++;
			show(temp);
		}
		temp = temp->next;
	}
	if (!counter) cout << "������ ���� " << str << " � ���������� ����� ��� � �������!\n";
}