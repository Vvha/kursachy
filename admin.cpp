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

	cout << "����� ��������: ";
	cin >> word;
	data.number = word;
	cout << "������� ��������: ";
	cin >> word;
	data.surname = word;
	/**/
	cout << "������ �������� ��� ���������: 1 ��� 2";
	cin >> c;
	if (c == 1) data.calltype = "��������";
	else if (c == 2) data.calltype = "���������";
	/**/
	cout << "����� ������: ";
	cin >> word;
	data.call_number = word;
	cout << "���� ���������� (������ - 00.00): ";
	cin >> word;
	data.call_date = ConvertStD(word);
	cout << "����� ���������� (������ - 00:00): ";
	cin >> word;
	data.call_time = ConvertStT(word);
	cout << "������������ ���������� (������ 00:00- ): ";
	cin >> word;
	data.callduration = ConvertStT(word);
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
	if (!temp) { cout << "������ ����� ���!"; return; }
	cout << "0. �����\n1. ��� ��������\n2. ��� ������\n3. ����� ������\n4. ���� ������\n5. ����� ������\n7. ������������\n";
	int choice, num;
	cin >> choice;
	string word;
	switch (choice) {
	case 0:
		cout << "����� ��������: ";
		cin >> word;
		temp->data.number = word;
		break;
	case 1:
		cout << "������� ��������: ";
		cin >> word;
		temp->data.surname = word;
		break;
	case 2:
		cout << "������ �������� ��� ���������: 1 ��� 2";
		cin >> num;
		if (num == 1) temp->data.calltype = "��������";
		else if (num == 2) temp->data.calltype = "���������";
		break;
	case 3:
		cout << "����� ������: ";
		cin >> word;
		temp->data.call_number = word;
		break;
	case 4:
		cout << "���� ���������� (������ - 00.00): ";
		cin >> word;
		temp->data.call_date = ConvertStD(word);
		break;
	case 5:
		cout << "����� ���������� (������ - 00:00): ";
		cin >> word;
		temp->data.call_time = ConvertStT(word);
		break;
	case 6:
		cout << "������������ ���������� (������ 00:00- ): ";
		cin >> word;
		temp->data.callduration = ConvertStT(word);
		break;
	default:
		break;
	}

	cout << "������ ������� ��������!";
}