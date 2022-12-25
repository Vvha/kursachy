#include "user.h"
// ���������� �����
void User::Obs_list(NODE* top)
{
	obs_list(top);
}
// ����� �� ������ ������
void User::searchByNum(NODE* top)
{
	cout << "������� ����� ������: ";
	int num;
	cin >> num;
	cout << "--------------------------------------------------------------\n";
	NODE* p = find(top, num);
	if (!p) { cout << "������ ������ ���!\n"; return; }
	show(p);
}
// ����� ���� �������, ������� ���� � �������� �����
void User::searchByDest(NODE* top)
{
	string ss;
	cout << "������� �����: ";
	cin >> ss;
	cout << "--------------------------------------------------------------\n";
	NODE* p = top;
	while (p) {
		if (p->data.dest_place.find(ss) != string::npos) show(p);
		p = p->GetNext();
	}
}
// ���������� �� ����
void User::SortByDate(NODE*& top)
{
	if (empty(top)) return;
	NODE* a, *b, *p, *h = NULL;

	for (NODE* i = top; i != NULL; ) {
		a = i;
		i = i->GetNext();
		b = h;
		for (p = NULL; (b != NULL) && (a->data.datedep < b->data.datedep); ) {
			p = b;
			b = b->GetNext();
		}
		if (p == NULL) {
			a->SetNext(h);
			h = a;
		}
		else {
			a->SetNext(b);
			p->SetNext(a);
		}
	}
	if (h != NULL)
		top = h;
	reset(top);

	std::cout << "������ �����������!";
}
// ������� ������
void User::BuyTicket(NODE*& top)
{
	int num;
	cout << "������� ����� ������: ";
	cin >> num;
	NODE* p = find(top, num);
	if (!p) { cout << "������ ������ ���!"; return; }
	if (!p->data.tick_left) { cout << "������� �� ������ ����� ��� � �������!"; return; }
	printf("��������� ������: %i\n�������� - %i\n", p->data.tick_cost, p->data.tick_left);
	cout << "������ ����� 0/1 - ";
	cin >> num;
	if (num) {
		cout << "������� ���������� �������: ";
		for (;;) {
			cin >> num;
			if (num > p->data.tick_left) {
				cout << "������ ���������� ������� ��� � �������!\n������� ������ �����: ";
				continue;
			}
			p->data.tick_left -= num;
			p->data.tick_sold += num;
			break;
		}
		cout << "������ ������� �������!";
	}
}

void User::showRange(NODE* top)
{
	NODE* p = top;
	string str, city;
	int a, b;
	cout << "������� �����: ";
	cin >> city;
	cout << "���� ��������� ���. ������: 00.00\n��: ";
	cin >> str;
	a = ConvertStD(str);
	cout << "��: ";
	cin >> str;
	b = ConvertStD(str);

	while (p) {
		if (p->data.dest_place.find(city) != string::npos && p->data.datedep > a && p->data.datedep < b) {
			show(p);
		}
		p = p->GetNext();
	}
}

