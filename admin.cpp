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
	int c = 0;
	int num;
	string word;
	do {
		switch (c) {
		case 0:
			cout << "����� ������: ";
			cin >> num;
			data.tr_num = num;
			break;
		case 1:
			cout << "����� �����������: ";
			cin >> word;
			data.dest_place = word;
			break;
		case 2:
			cout << "���� �����������: ";
			cin >> word;
			data.datedep = ConvertStD(word);
			break;
		case 3:
			cout << "����� �����������: ";
			cin >> word;
			data.timedep = ConvertStT(word);
			break;
		case 4:
			cout << "����� ��������: ";
			cin >> word;
			data.timearr = ConvertStT(word);
			break;
		case 5:
			cout << "���� ������: ";
			cin >> num;
			data.tick_cost = num;
			break;
		case 6:
			cout << "���������� ����������: ";
			cin >> num;
			data.tick_left = num;
			break;
		case 7:
			cout << "���������� ��������: ";
			cin >> num;
			data.tick_sold = num;
			break;
		default:
			break;
		}
		c++;
	} while (c != 7);
	append(top, data);
	cout << "������ ������� ��������� � ������!";
}
// �������� ������
void Admin::Del(NODE*& top, int ind)
{
	NODE* p = find(top, ind);
	if (!p) {
		cout << "������ � ����� ������� ���!";
		return;
	}
	if (p->data.id == 1) pop_head(top);
	else {
		p = findById(top, p->data.id - 1);
		if (!p) return;
		pop_after(p);
	}
	reset(top);
	cout << "������ ������� ������� �� ������!";
}
// ��������� ������
void Admin::Edit(NODE*& top, int id)
{
	NODE* temp = find(top, id);
	if (!temp) { cout << "������ ����� ���!"; return; }
	cout << "0. ����\n1. ���\n2. ����� ��������\n3. ���� ������\n4. ����� ������\n5. ����� ��������\n7. ������ �����\n8. ���� ������\n9. ������\n10. ���� ������\n";
	int choice, num;
	cin >> choice;
	string word;
	switch (choice) {
	case 0:
		cin >> num;
		temp->data.tr_num = num;
		break;
	case 1:
		cin >> word;
		temp->data.dest_place = word;
		break;
	case 2:
		cin >> word;
		temp->data.datedep = ConvertStD(word);
		break;
	case 3:
		cin >> word;
		temp->data.timedep = ConvertStT(word);
		break;
	case 4:
		cin >> word;
		temp->data.timearr = ConvertStT(word);
		break;
	case 5:
		cin >> num;
		temp->data.tick_cost = num;
		break;
	case 6:
		cin >> num;
		temp->data.tick_left = num;
		break;
	case 7:
		cin >> num;
		temp->data.tick_sold = num;
		break;
	default:
		break;
	}

	cout << "������ ������� ��������!";
}
