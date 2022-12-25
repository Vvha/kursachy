#include "admin.h"
// �������� ������
void Admin::Obs_list(NODE* top)
{
	obs_list(top);
}
// ���������� ����� ������
void Admin::Add(NODE*& top)
{
	DATA data;
	int c;
	string word;

	cout << "��� ������.\n1. �����\n2. �������\n ";
	do {
		cin >> c;
		if (c == 1)data.vouch_type = "�����";
		else if (c == 2) data.vouch_type = "�������";
		else cout << "�������� ����! ���������� �����";
	} while (c != 1 && c != 2);

	cout << "���������� ����: ";
	cin >> c;
	data.days_amount = c;

	cout << "������� ��� �������:\n1. �������\n2. �� ��������\n";
	do {
		cin >> c;
		if (c == 1)data.nutrition = "�������";
		else if (c == 2) data.nutrition = "�� ��������";
		else cout << "�������� ����! ���������� �����\n";
	} while (c != 1 && c != 2);

	cout << "���������: ";
	cin >> c;

	data.cost = c;
	append(top, data);
	cout << "������ ���������";
}
// �������� ������
void Admin::Del(NODE*& top, int ind)
{
	NODE* p = find(top, ind);
	if (!p) {
		cout << "����������� �����";
		return;
	}
	if (p->data.id == 1) pop_head(top);
	else {
		p = find(top, p->data.id - 1);
		if (!p) return;
		pop_after(p);
	}
	reset(top);
	cout << "������ �������";
}
// ��������� ������
void Admin::Edit(NODE*& top, int id)
{
	NODE* temp = find(top, id);
	if (!temp) { cout << "����� ������ ��� � ������!"; return; }
	cout << "1. ������\n2. ���������� ����\n3. �������\n4. ���������\n";
	int choice = 0, num;
	cin >> choice;
	string word;
	system("cls");
	switch (choice) {
	case 1:
		cout << "��� ������.\n1. �����\n2. �������\n ";
		do {
			cin >> choice;
			if (choice == 1)temp->data.vouch_type = "�����";
			else if (choice == 2) temp->data.vouch_type = "�������";
			else cout << "�������� ����! ���������� �����";
		} while (choice != 1 && choice != 2);
		break;
	case 2:
		cout << "������� ���������� ����: ";
		cin >> num;
		temp->data.days_amount = num;
		break;
	case 3:
		cout << "������� ��� �������:\n1. �������\n2. �� ��������\n";
		do {
			cin >> choice;
			if (choice == 1) temp->data.nutrition = "�������";
			else if (choice == 2) temp->data.vouch_type = "�� ��������";
			else cout << "�������� ����! ���������� �����\n";
		} while (choice != 1 && choice != 2);
		break;
	case 4:
		cout << "������� ���������: ";
		cin >> num;
		temp->data.cost = num;
	default:
		break;
	}

	cout << "������ ������� ��������!";
}