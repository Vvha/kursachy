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

	cout << "Тип путёвки.\n1. Отдых\n2. Лечение\n ";
	do {
		cin >> c;
		if (c == 1)data.vouch_type = "Отдых";
		else if (c == 2) data.vouch_type = "Лечение";
		else cout << "Неверный ввод! Попробуйте снова";
	} while (c != 1 && c != 2);

	cout << "Количество дней: ";
	cin >> c;
	data.days_amount = c;

	cout << "Введите тип питания:\n1. Завтрак\n2. Всё включено\n";
	do {
		cin >> c;
		if (c == 1)data.nutrition = "завтрак";
		else if (c == 2) data.nutrition = "всё включено";
		else cout << "Неверный ввод! Попробуйте снова\n";
	} while (c != 1 && c != 2);

	cout << "Стоимость: ";
	cin >> c;

	data.cost = c;
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
	if (!temp) { cout << "Такой путёвки нет в списке!"; return; }
	cout << "1. путёвка\n2. Количество дней\n3. Питание\n4. Стоимость\n";
	int choice = 0, num;
	cin >> choice;
	string word;
	system("cls");
	switch (choice) {
	case 1:
		cout << "Тип путёвки.\n1. Отдых\n2. Лечение\n ";
		do {
			cin >> choice;
			if (choice == 1)temp->data.vouch_type = "Отдых";
			else if (choice == 2) temp->data.vouch_type = "Лечение";
			else cout << "Неверный ввод! Попробуйте снова";
		} while (choice != 1 && choice != 2);
		break;
	case 2:
		cout << "Введите количество дней: ";
		cin >> num;
		temp->data.days_amount = num;
		break;
	case 3:
		cout << "Введите тип питания:\n1. Завтрак\n2. Всё включено\n";
		do {
			cin >> choice;
			if (choice == 1) temp->data.nutrition = "завтрак";
			else if (choice == 2) temp->data.vouch_type = "всё включено";
			else cout << "Неверный ввод! Попробуйте снова\n";
		} while (choice != 1 && choice != 2);
		break;
	case 4:
		cout << "Введите стоимость: ";
		cin >> num;
		temp->data.cost = num;
	default:
		break;
	}

	cout << "Запись успешно изменена!";
}