#include "admin.h"
// просмотр списка
void Admin::Obs_list(NODE* top)
{
	obs_list(top);
}
// добавление новой записи
void Admin::Add(NODE*& top)
{
	DATA data;
	int c;
	string word;

	cout << "Номер водителя: ";
	cin >> word;
	data.number = word;
	cout << "Фамилия водителя: ";
	cin >> word;
	data.surname = word;
	/**/
	cout << "Звонок входящий или исходящий: 1 или 2";
	cin >> c;
	if (c == 1) data.calltype = "входящий";
	else if (c == 2) data.calltype = "исходящий";
	/**/
	cout << "Номер вызова: ";
	cin >> word;
	data.call_number = word;
	cout << "дата переговора (формат - 00.00): ";
	cin >> word;
	data.call_date = ConvertStD(word);
	cout << "время переговора (формат - 00:00): ";
	cin >> word;
	data.call_time = ConvertStT(word);
	cout << "Длительность переговора (формат 00:00- ): ";
	cin >> word;
	data.callduration = ConvertStT(word);
	append(top, data);
	cout << "Запись добавлена";
}
// удаление записи
void Admin::Del(NODE*& top, int ind)
{
	NODE* p = find(top, ind);
	if (!p) {
		cout << "неправильно введён";
		return;
	}
	if (p->data.id == 1) pop_head(top);
	else {
		p = find(top, p->data.id - 1);
		if (!p) return;
		pop_after(p);
	}
	reset(top);
	cout << "Запись удалена";
}
// изменение записи
void Admin::Edit(NODE*& top, int id)
{
	NODE* temp = find(top, id);
	if (!temp) { cout << "Такого рейса нет!"; return; }
	cout << "0. номер\n1. имя водителя\n2. тип звонка\n3. номер вызова\n4. дата вызова\n5. Время вызова\n7. длительность\n";
	int choice, num;
	cin >> choice;
	string word;
	switch (choice) {
	case 0:
		cout << "Номер водителя: ";
		cin >> word;
		temp->data.number = word;
		break;
	case 1:
		cout << "Фамилия водителя: ";
		cin >> word;
		temp->data.surname = word;
		break;
	case 2:
		cout << "Звонок входящий или исходящий: 1 или 2";
		cin >> num;
		if (num == 1) temp->data.calltype = "входящий";
		else if (num == 2) temp->data.calltype = "исходящий";
		break;
	case 3:
		cout << "Номер вызова: ";
		cin >> word;
		temp->data.call_number = word;
		break;
	case 4:
		cout << "дата переговора (формат - 00.00): ";
		cin >> word;
		temp->data.call_date = ConvertStD(word);
		break;
	case 5:
		cout << "время переговора (формат - 00:00): ";
		cin >> word;
		temp->data.call_time = ConvertStT(word);
		break;
	case 6:
		cout << "Длительность переговора (формат 00:00- ): ";
		cin >> word;
		temp->data.callduration = ConvertStT(word);
		break;
	default:
		break;
	}

	cout << "Запись успешно изменена!";
}